/**
  ******************************************************************************
  * @file    layers_upsample_generic.h
  * @author  Cyril Enault
  * @brief   header file of AI platform padding generic datatypes
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @verbatim
  @endverbatim
  ******************************************************************************
  */
#ifndef LAYERS_UPSAMPLE_H
#define LAYERS_UPSAMPLE_H
#pragma once

#include "layers_generic.h"

/*!
 * @defgroup layers_pad_generic Layers Definitions
 * @brief definition
 *
 */
AI_API_DECLARE_BEGIN


/******************************************************************************/
/*  Forward Functions Section                                                 */
/******************************************************************************/


/*!
 * @brief Handles  upsampling in zeros mode
 * @ingroup layers_upsample
 * @param layer upsample layer
 */
AI_INTERNAL_API
void forward_upsample_zeros_is8os8(ai_layer* layer);
AI_API_DECLARE_END

#endif    /*LAYERS_UPSAMPLE_H*/
