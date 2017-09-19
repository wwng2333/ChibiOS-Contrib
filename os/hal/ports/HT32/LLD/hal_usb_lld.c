/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
                        (C) 2017 Charlie Waters <cawiii@me.com>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_usb_lld.c
 * @brief   PLATFORM USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include "hal.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver identifier.
 */
#if HT32_USB_USE_USB0 || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   EP0 state.
 * @note    It is an union because IN and OUT endpoints are never used at the
 *          same time for EP0.
 */
static union {
    /**
   * @brief   IN EP0 state.
   */
    USBInEndpointState in;
    /**
   * @brief   OUT EP0 state.
   */
    USBOutEndpointState out;
} ep0_state;

/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
    USB_EP_MODE_TYPE_CTRL,
    _usb_ep0setup,
    _usb_ep0in,
    _usb_ep0out,
    0x40,
    0x40,
    &ep0_state.in,
    &ep0_state.out
};

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static u32 usb_get_int_flags(void){
    return USB->USBIER.word & USB->USBISR.word;
}

static void usb_clear_int_flags(u32 flags){
    // flags are cleared by writing 1
    // except ESOFIF, which is written normally
    USB->USBISR.word = (USB->USBISR.word & USBISR_ESOFIF) | flags;
}

static u32 usb_get_ep_int_flags(int ep){
    return USB->USBEP[ep].IER.word & USB->USBEP[ep].ISR.word;
}

static void usb_clear_ep_int_flags(int ep, u32 flags){
    // flags are cleared by writing 1
    USB->USBEP[ep].ISR.word = flags;
}

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/

#if (HT32_USB_USE_USB0 == TRUE) || defined(__DOXYGEN__) || 1

/**
 * @brief USB interrupt handler.
 * @isr
 */

OSAL_IRQ_HANDLER(HT32_USB_IRQ_VECTOR) {
    USBDriver *usbp = &USBD1;
    OSAL_IRQ_PROLOGUE();

    u32 isr = usb_get_int_flags();

    // Start of Frame Interrupt
    if(isr & USBISR_SOFIF){
        // Start of Frame callback
        _usb_isr_invoke_sof_cb(usbp);
        usb_clear_int_flags(USBISR_SOFIF);
    }

    // Suspend Interrupt
    if(isr & USBISR_SUSPIF){
        usb_clear_int_flags(USBISR_SUSPIF);
        // Suspend routine and event callback
        _usb_suspend(usbp);
    }

    // Reset Interrupt
    if(isr & USBISR_URSTIF){
        // Reset routine and event callback
        _usb_reset(usbp);
        usb_clear_int_flags(USBISR_URSTIF);
    }

    // Resume Interrupt
    if(isr & USBISR_RSMIF){
        // Resume/Wakeup routine and callback
        _usb_wakeup(usbp);
        usb_clear_int_flags(USBISR_RSMIF);
    }

    // EP0 Interrupt
    if(isr & USBISR_EP0IF){
        u32 episr = usb_get_ep_int_flags(EP_0);

        // SETUP Token Received
        if(episr & USBEPnISR_STRXIF){
            usb_clear_ep_int_flags(EP_0, USBEPnISR_STRXIF);
        }

        // SETUP Data Received
        if(episr & USBEPnISR_SDRXIF){
            // SETIP callback
            _usb_isr_invoke_setup_cb(usbp, 0);
            usb_clear_ep_int_flags(EP_0, USBEPnISR_SDRXIF);
//            usb_lld_read_setup(usbp, 0, );
        }

        // OUT Token Received
        if(episr & USBEPnISR_OTRXIF){
            usb_clear_ep_int_flags(EP_0, USBEPnISR_OTRXIF);
        }

        // OUT Data Received
        if(episr & USBEPnISR_ODRXIF){
            // OUT callback
            _usb_isr_invoke_out_cb(usbp, 0);
            usb_clear_ep_int_flags(EP_0, USBEPnISR_ODRXIF);
        }

        // IN Token Received
        if(episr & USBEPnISR_ITRXIF){
            usb_clear_ep_int_flags(EP_0, USBEPnISR_ITRXIF);
        }

        // IN Data Transmitted
        if(episr & USBEPnISR_IDTXIF){
            // IN callback
            _usb_isr_invoke_in_cb(usbp, 0);
            usb_clear_ep_int_flags(EP_0, USBEPnISR_IDTXIF);
        }

        // STALL Transmitted
        if(episr & USBEPnISR_STLIF){
            usb_clear_ep_int_flags(EP_0, USBEPnISR_STLIF);

        }

        usb_clear_int_flags(USBISR_EP0IF);
    }

    // EP 1-7 Interrupt
    u32 mask = USBISR_EP1IF;
    for(int i = 1; i < 8; ++i){
        // EPn Interrupt
        if(isr & mask){
            u32 episr = usb_get_ep_int_flags(i);

            // OUT Token Received
            if(episr & USBEPnISR_OTRXIF){
                usb_clear_ep_int_flags(i, USBEPnISR_OTRXIF);
            }

            // OUT Data Received
            if(episr & USBEPnISR_ODRXIF){
                // OUT callback
                _usb_isr_invoke_out_cb(usbp, i);
                usb_clear_ep_int_flags(i, USBEPnISR_ODRXIF);
            }

            // IN Token Received
            if(episr & USBEPnISR_ITRXIF){
                usb_clear_ep_int_flags(i, USBEPnISR_ITRXIF);
            }

            // IN Data Transmitted
            if(episr & USBEPnISR_IDTXIF){
                // IN callback
                _usb_isr_invoke_in_cb(usbp, i);
            }

            // STALL Transmitted
            if(episr & USBEPnISR_STLIF){
                usb_clear_ep_int_flags(i, USBEPnISR_STLIF);
            }

            usb_clear_int_flags(mask);
        }
        mask = mask << 1;
    }

    OSAL_IRQ_EPILOGUE();
}

#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void){
#if HT32_USB_USE_USB0 == TRUE
    /* Driver initialization.*/
    usbObjectInit(&USBD1);
#endif // HT32_USB_USE_USB1

    // enable USB clock
    CKCU->AHBCCR.USBEN = 1;
    // set usb prescaler
    CKCU->GCFGR.USBPRE = 2;

    // enable usb interrupts
    USB->USBIER.word = USBIER_UGIE |
                       USBIER_EP0IE | USBIER_EP1IE | USBIER_EP2IE |
                       USBIER_URSTIE | USBIER_RSMIE | USBIER_SUSPIE;

    // enable usb IRQ
    nvicEnableVector(USB_IRQn, 1);
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp){
    if (usbp->state == USB_STOP) {
        /* Enables the peripheral.*/
#if HT32_USB_USE_USB0 == TRUE
        if (&USBD1 == usbp) {

        }
#endif // HT32_USB_USE_USB1
    }
    /* Configures the peripheral.*/
}

/**
 * @brief   Deactivates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_stop(USBDriver *usbp) {

    if (usbp->state == USB_READY) {
        /* Resets the peripheral.*/

        /* Disables the peripheral.*/
#if HT32_USB_USE_USB0 == TRUE
        if (&USBD1 == usbp) {

        }
#endif
    }
}

/**
 * @brief   USB low level reset routine.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_reset(USBDriver *usbp) {
    // USB Reset
    RSTCU->AHBPRSTR.USBRST = 1;
    // Clear CSR, except for DP pull up
    USB->USBCSR.word &= USBCSR_DPPUEN;

    usbp->address = 0;
    usb_lld_set_address(usbp);

    /* Post reset initialization.*/

    /* EP0 initialization.*/
    usbp->epc[0] = &ep0config;
    usb_lld_init_endpoint(usbp, 0);
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {
    USB->USBCSR.ADRSET = 1;
    USB->USBDEVA.DEVA = usbp->address & 0x7f;
}

/**
 * @brief   Enables an endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep) {
    if(ep > USB_MAX_ENDPOINTS)
        return;

    const USBEndpointConfig *epcp = usbp->epc[ep];

    switch(epcp->ep_mode & USB_EP_MODE_TYPE){
        case USB_EP_MODE_TYPE_CTRL:
            break;
        case USB_EP_MODE_TYPE_ISOC:
            break;
        case USB_EP_MODE_TYPE_BULK:
            break;
        case USB_EP_MODE_TYPE_INTR:
            break;
        default:
            return;
    }

    if(ep){
        USB->USBEP[ep].CFGR.word |= USBEPnCFGR_EPEN;
    }

    (void)usbp;
}

/**
 * @brief   Disables all the active endpoints except the endpoint zero.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp) {
    (void)usbp;

    for(int i = 1; i < USB_MAX_ENDPOINTS; ++i)
        USB->USBEP[i].CFGR.word &= ~USBEPnCFGR_EPEN;
}

/**
 * @brief   Returns the status of an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep)
{
    (void)usbp;
    (void)ep;

//    usbp->epc[ep]->

    return EP_STATUS_DISABLED;
}

/**
 * @brief   Returns the status of an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

  return EP_STATUS_DISABLED;
}

/**
 * @brief   Reads a setup packet from the dedicated packet buffer.
 * @details This function must be invoked in the context of the @p setup_cb
 *          callback in order to read the received setup packet.
 * @pre     In order to use this function the endpoint must have been
 *          initialized as a control endpoint.
 * @post    The endpoint is ready to accept another packet.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @param[out] buf      buffer where to copy the packet data
 *
 * @notapi
 */
void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf) {

  (void)usbp;
  (void)ep;
  (void)buf;

}

/**
 * @brief   Prepares for a receive operation.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_prepare_receive(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Prepares for a transmit operation.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_prepare_transmit(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Starts a receive operation on an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an OUT endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an IN endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an OUT endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an IN endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;

}

#endif /* HAL_USE_USB == TRUE */

/** @} */
