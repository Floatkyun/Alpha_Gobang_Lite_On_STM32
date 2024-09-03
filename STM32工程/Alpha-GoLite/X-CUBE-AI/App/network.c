/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Sep  2 22:39:41 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "0xe19dc6feddc9e2cdbc4a64ef78f776c9"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Sep  2 22:39:41 2024"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

static ai_ptr g_network_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 486, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  input_Transpose_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 486, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_Relu_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_Relu_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_Relu_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_Relu_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3402, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_down_MaxPool_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_Concat_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_up_Resize_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_Concat_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_act_Mul_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_up_Resize_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_Concat_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_act_Mul_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_up_Resize_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_Concat_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_Add_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Div_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Erf_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Mul_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2592, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  _conv3_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2592, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  _Concat_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5994, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10368, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  _conv4_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10368, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 81, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_conv_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 81, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_Flatten_output_0_to_chlast_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 81, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_1_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  node_384_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 162, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_conv_Relu_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 162, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_Flatten_output_0_to_chlast_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 162, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 81, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  output_softmax_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 81, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  output_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 81, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2268, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15876, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 42, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Constant_output_0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 85248, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10368, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 13122, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 81, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_weights, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 42, 4, 4, 16), AI_STRIDE_INIT(4, 4, 168, 2688, 10752),
  1, &_conv2_conv_Conv_output_0_weights_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_bias, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_conv2_conv_Conv_output_0_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_weights, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 7, 1, 16), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &_ULite_e1_dw_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_bias, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_e1_dw_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_weights, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 16), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &_ULite_e1_dw_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_bias, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_e1_dw_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_scale, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_e1_bn_BatchNormalization_output_0_scale_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_bias, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_e1_bn_BatchNormalization_output_0_bias_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_weights, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 4, 64, 2048, 2048),
  1, &_ULite_e1_pw_Conv_output_0_weights_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_bias, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e1_pw_Conv_output_0_bias_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Constant_output_0, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &_ULite_e1_act_Constant_output_0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_scale, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e1_act_Add_output_0_scale_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e1_act_Add_output_0_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_scale, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e1_act_Mul_1_output_0_scale_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_bias, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e1_act_Mul_1_output_0_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_weights, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 7, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_e2_dw_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_bias, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e2_dw_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_weights, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_e2_dw_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e2_dw_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_scale, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e2_bn_BatchNormalization_output_0_scale_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_e2_bn_BatchNormalization_output_0_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_weights, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 4, 128, 8192, 8192),
  1, &_ULite_e2_pw_Conv_output_0_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e2_pw_Conv_output_0_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_scale, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e2_act_Add_output_0_scale_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_bias, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e2_act_Add_output_0_bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_scale, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e2_act_Mul_1_output_0_scale_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e2_act_Mul_1_output_0_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 7, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &_ULite_e3_dw_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e3_dw_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &_ULite_e3_dw_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e3_dw_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_scale, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e3_bn_BatchNormalization_output_0_scale_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_e3_bn_BatchNormalization_output_0_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_weights, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 4, 256, 32768, 32768),
  1, &_ULite_e3_pw_Conv_output_0_weights_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_pw_Conv_output_0_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_scale, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_act_Add_output_0_scale_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_act_Add_output_0_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_weights, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 32), AI_STRIDE_INIT(4, 4, 512, 16384, 16384),
  1, &_ULite_b5_pw1_Conv_output_0_weights_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_pw1_Conv_output_0_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_weights, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_b5_dw3_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_bias, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw3_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_weights, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 3, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_b5_dw3_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw3_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_weights, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_b5_dw2_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_bias, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw2_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_weights, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 3, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_b5_dw2_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_bias, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw2_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_weights, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_b5_dw1_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_bias, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw1_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_weights, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 3, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_b5_dw1_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_bias, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw1_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_weights, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 4, 512, 65536, 65536),
  1, &_ULite_b5_pw2_Conv_output_0_weights_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_bias, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_pw2_Conv_output_0_bias_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_scale, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Mul_1_output_0_scale_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_bias, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Mul_1_output_0_bias_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_weights, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 64), AI_STRIDE_INIT(4, 4, 768, 49152, 49152),
  1, &_ULite_d3_pw_Conv_output_0_weights_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_bias, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_d3_pw_Conv_output_0_bias_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_weights, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 7, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &_ULite_d3_dw_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_bias, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_d3_dw_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  input_output, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 9, 9, 6), AI_STRIDE_INIT(4, 4, 4, 36, 324),
  1, &input_output_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  input_Transpose_output, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 9, 9), AI_STRIDE_INIT(4, 4, 4, 24, 216),
  1, &input_Transpose_output_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_weights, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &_ULite_d3_dw_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_output, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_conv1_conv_Conv_output_0_output_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_bias, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_d3_dw_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_Relu_output_0_output, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_conv1_Relu_output_0_output_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_output, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_0_conv1_Conv_output_0_output_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_weights, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 4, 256, 16384, 16384),
  1, &_ULite_d3_pw2_Conv_output_0_weights_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_Relu_output_0_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_0_Relu_output_0_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_bias, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_ULite_d3_pw2_Conv_output_0_bias_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_output, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_0_conv2_Conv_output_0_output_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_Add_output_0_output, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_0_Add_output_0_output_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_Relu_1_output_0_output, AI_STATIC,
  71, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_0_Relu_1_output_0_output_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_output, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_1_conv1_Conv_output_0_output_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_Relu_output_0_output, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_1_Relu_output_0_output_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_output, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_1_conv2_Conv_output_0_output_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_Add_output_0_output, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_1_Add_output_0_output_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_Relu_1_output_0_output, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_1_Relu_1_output_0_output_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_weights, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 32), AI_STRIDE_INIT(4, 4, 384, 12288, 12288),
  1, &_ULite_d2_pw_Conv_output_0_weights_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_output, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_2_conv1_Conv_output_0_output_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_bias, AI_STATIC,
  79, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_d2_pw_Conv_output_0_bias_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_Relu_output_0_output, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_2_Relu_output_0_output_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_output, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_2_conv2_Conv_output_0_output_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_weights, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 7, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_d2_dw_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_Add_output_0_output, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_2_Add_output_0_output_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_bias, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_d2_dw_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_Relu_1_output_0_output, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_2_Relu_1_output_0_output_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_output, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_3_conv1_Conv_output_0_output_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_weights, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &_ULite_d2_dw_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_Relu_output_0_output, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_3_Relu_output_0_output_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_bias, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_d2_dw_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_output, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_3_conv2_Conv_output_0_output_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_Add_output_0_output, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_3_Add_output_0_output_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_weights, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &_ULite_d2_pw2_Conv_output_0_weights_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_Relu_1_output_0_output, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 9, 9), AI_STRIDE_INIT(4, 4, 4, 168, 1512),
  1, &_residues_residues_3_Relu_1_output_0_output_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_bias, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_d2_pw2_Conv_output_0_bias_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_output, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_conv2_conv_Conv_output_0_output_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_Relu_output_0_output, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_conv2_Relu_output_0_output_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_output, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_e1_dw_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_output, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_e1_dw_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_Add_output_0_output, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_e1_dw_Add_output_0_output_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_dw_Add_1_output_0_output, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_e1_dw_Add_1_output_0_output_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_output, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_e1_bn_BatchNormalization_output_0_output_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_output, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e1_pw_Conv_output_0_output_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_weights, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 4, 192, 3072, 3072),
  1, &_ULite_d1_pw_Conv_output_0_weights_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Div_output_0_output, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e1_act_Div_output_0_output_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_bias, AI_STATIC,
  105, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_pw_Conv_output_0_bias_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Erf_output_0_output, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e1_act_Erf_output_0_output_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_output, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e1_act_Add_output_0_output_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_weights, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 7, 1, 16), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &_ULite_d1_dw_dw_w_Conv_output_0_weights_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Mul_output_0_output, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e1_act_Mul_output_0_output_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_bias, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_dw_dw_w_Conv_output_0_bias_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_output, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e1_act_Mul_1_output_0_output_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_output, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e2_dw_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_weights, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 16), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &_ULite_d1_dw_dw_h_Conv_output_0_weights_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_output, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e2_dw_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_bias, AI_STATIC,
  115, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_dw_dw_h_Conv_output_0_bias_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_Add_output_0_output, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e2_dw_Add_output_0_output_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_dw_Add_1_output_0_output, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e2_dw_Add_1_output_0_output_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_weights, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 16), AI_STRIDE_INIT(4, 4, 64, 1024, 1024),
  1, &_ULite_d1_pw2_Conv_output_0_weights_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_output, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_e2_bn_BatchNormalization_output_0_output_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_bias, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_pw2_Conv_output_0_bias_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_output, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e2_pw_Conv_output_0_output_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Div_output_0_output, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e2_act_Div_output_0_output_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_scale, AI_STATIC,
  123, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_act_Add_output_0_scale_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Erf_output_0_output, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e2_act_Erf_output_0_output_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_bias, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_act_Add_output_0_bias_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_output, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e2_act_Add_output_0_output_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Mul_output_0_output, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e2_act_Mul_output_0_output_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_scale, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_act_Mul_1_output_0_scale_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_output, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e2_act_Mul_1_output_0_output_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_bias, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &_ULite_d1_act_Mul_1_output_0_bias_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_output, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e3_dw_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_output, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e3_dw_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_weights, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 16, 4, 4, 32), AI_STRIDE_INIT(4, 4, 64, 2048, 8192),
  1, &_conv3_conv_Conv_output_0_weights_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_Add_output_0_output, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e3_dw_Add_output_0_output_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_bias, AI_STATIC,
  135, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_conv3_conv_Conv_output_0_bias_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_dw_Add_1_output_0_output, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e3_dw_Add_1_output_0_output_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_output, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_e3_bn_BatchNormalization_output_0_output_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_weights, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 74, 3, 3, 128), AI_STRIDE_INIT(4, 4, 296, 37888, 113664),
  1, &_conv4_conv_Conv_output_0_weights_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_output, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 4, 4, 512, 1024),
  1, &_ULite_e3_pw_Conv_output_0_output_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_bias, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_conv4_conv_Conv_output_0_bias_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_down_MaxPool_output_0_output, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_down_MaxPool_output_0_output_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_act_Div_output_0_output, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_act_Div_output_0_output_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_weights, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 1), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &_value_head_conv_conv_Conv_output_0_weights_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_act_Erf_output_0_output, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_act_Erf_output_0_output_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_bias, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &_value_head_conv_conv_Conv_output_0_bias_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_output, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_act_Add_output_0_output_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e3_act_Mul_output_0_output, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_e3_act_Mul_output_0_output_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_weights, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 81, 128, 1, 1), AI_STRIDE_INIT(4, 4, 324, 41472, 41472),
  1, &_value_head_fc_fc_0_Gemm_output_0_weights_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_output, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_pw1_Conv_output_0_output_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_bias, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_value_head_fc_fc_0_Gemm_output_0_bias_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_output, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw3_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_output, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw3_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_weights, AI_STATIC,
  153, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 1), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &_value_head_fc_fc_2_Gemm_output_0_weights_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_Add_output_0_output, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw3_Add_output_0_output_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_bias, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &_value_head_fc_fc_2_Gemm_output_0_bias_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw3_Add_1_output_0_output, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw3_Add_1_output_0_output_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_output, AI_STATIC,
  157, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw2_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_weights, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 2), AI_STRIDE_INIT(4, 4, 512, 1024, 1024),
  1, &_policy_head_conv_conv_Conv_output_0_weights_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_output, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw2_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_bias, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &_policy_head_conv_conv_Conv_output_0_bias_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_Add_output_0_output, AI_STATIC,
  161, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw2_Add_output_0_output_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw2_Add_1_output_0_output, AI_STATIC,
  162, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw2_Add_1_output_0_output_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_weights, AI_STATIC,
  163, 0x0,
  AI_SHAPE_INIT(4, 162, 81, 1, 1), AI_STRIDE_INIT(4, 4, 648, 52488, 52488),
  1, &_policy_head_fc_Gemm_output_0_weights_array, NULL)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_output, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw1_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_bias, AI_STATIC,
  165, 0x0,
  AI_SHAPE_INIT(4, 1, 81, 1, 1), AI_STRIDE_INIT(4, 4, 4, 324, 324),
  1, &_policy_head_fc_Gemm_output_0_bias_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_output, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw1_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_Add_output_0_output, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw1_Add_output_0_output_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_dw1_Add_1_output_0_output, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &_ULite_b5_dw1_Add_1_output_0_output_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_Concat_output_0_output, AI_STATIC,
  169, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_Concat_output_0_output_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_scratch0, AI_STATIC,
  170, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 8, 2), AI_STRIDE_INIT(4, 4, 4, 128, 1024),
  1, &_ULite_e1_pw_Conv_output_0_scratch0_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_output, AI_STATIC,
  171, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_pw2_Conv_output_0_output_array, NULL)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Div_output_0_output, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Div_output_0_output_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Erf_output_0_output, AI_STATIC,
  173, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Erf_output_0_output_array, NULL)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Add_output_0_output, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Add_output_0_output_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_scratch0, AI_STATIC,
  175, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 4, 2), AI_STRIDE_INIT(4, 4, 4, 256, 1024),
  1, &_ULite_e2_pw_Conv_output_0_scratch0_array, NULL)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Mul_output_0_output, AI_STATIC,
  176, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Mul_output_0_output_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_output, AI_STATIC,
  177, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_ULite_b5_act_Mul_1_output_0_output_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_up_Resize_output_0_output, AI_STATIC,
  178, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 4, 4, 512, 1024),
  1, &_ULite_d3_up_Resize_output_0_output_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_Concat_output_0_output, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 2, 2), AI_STRIDE_INIT(4, 4, 4, 768, 1536),
  1, &_ULite_d3_Concat_output_0_output_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_output, AI_STATIC,
  180, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_pw_Conv_output_0_output_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_output, AI_STATIC,
  181, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_dw_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_output, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_dw_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_Add_output_0_output, AI_STATIC,
  183, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_dw_Add_output_0_output_array, NULL)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_dw_Add_1_output_0_output, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_dw_Add_1_output_0_output_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_output, AI_STATIC,
  185, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_pw2_Conv_output_0_output_array, NULL)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_act_Div_output_0_output, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_act_Div_output_0_output_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_act_Erf_output_0_output, AI_STATIC,
  187, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_act_Erf_output_0_output_array, NULL)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_act_Add_output_0_output, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_act_Add_output_0_output_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_act_Mul_output_0_output, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_act_Mul_output_0_output_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d3_act_Mul_1_output_0_output, AI_STATIC,
  190, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 4, 4, 256, 512),
  1, &_ULite_d3_act_Mul_1_output_0_output_array, NULL)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_up_Resize_output_0_output, AI_STATIC,
  191, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 4, 4, 256, 1024),
  1, &_ULite_d2_up_Resize_output_0_output_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_Concat_output_0_output, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &_ULite_d2_Concat_output_0_output_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_output, AI_STATIC,
  193, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_pw_Conv_output_0_output_array, NULL)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_output, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_dw_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_output, AI_STATIC,
  195, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_dw_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_Add_output_0_output, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_dw_Add_output_0_output_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_dw_Add_1_output_0_output, AI_STATIC,
  197, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_dw_Add_1_output_0_output_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_output, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_pw2_Conv_output_0_output_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_act_Div_output_0_output, AI_STATIC,
  199, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_act_Div_output_0_output_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_act_Erf_output_0_output, AI_STATIC,
  200, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_act_Erf_output_0_output_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_act_Add_output_0_output, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_act_Add_output_0_output_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_act_Mul_output_0_output, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_act_Mul_output_0_output_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d2_act_Mul_1_output_0_output, AI_STATIC,
  203, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 4, 4, 128, 512),
  1, &_ULite_d2_act_Mul_1_output_0_output_array, NULL)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_up_Resize_output_0_output, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 4, 4, 128, 1024),
  1, &_ULite_d1_up_Resize_output_0_output_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_Concat_output_0_output, AI_STATIC,
  205, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 8, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1536),
  1, &_ULite_d1_Concat_output_0_output_array, NULL)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_output, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_pw_Conv_output_0_output_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_output, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_dw_dw_w_Conv_output_0_output_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_output, AI_STATIC,
  208, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_dw_dw_h_Conv_output_0_output_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_Add_output_0_output, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_dw_Add_output_0_output_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_dw_Add_1_output_0_output, AI_STATIC,
  210, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_dw_Add_1_output_0_output_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_output, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_pw2_Conv_output_0_output_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Div_output_0_output, AI_STATIC,
  212, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_act_Div_output_0_output_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Erf_output_0_output, AI_STATIC,
  213, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_act_Erf_output_0_output_array, NULL)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_output, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_act_Add_output_0_output_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Mul_output_0_output, AI_STATIC,
  215, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_act_Mul_output_0_output_array, NULL)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_output, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 8, 8), AI_STRIDE_INIT(4, 4, 4, 64, 512),
  1, &_ULite_d1_act_Mul_1_output_0_output_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_output, AI_STATIC,
  217, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 9, 9), AI_STRIDE_INIT(4, 4, 4, 128, 1152),
  1, &_conv3_conv_Conv_output_0_output_array, NULL)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  _conv3_Relu_output_0_output, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 9, 9), AI_STRIDE_INIT(4, 4, 4, 128, 1152),
  1, &_conv3_Relu_output_0_output_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  _Concat_output_0_output, AI_STATIC,
  219, 0x0,
  AI_SHAPE_INIT(4, 1, 74, 9, 9), AI_STRIDE_INIT(4, 4, 4, 296, 2664),
  1, &_Concat_output_0_output_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_output, AI_STATIC,
  220, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 9, 9), AI_STRIDE_INIT(4, 4, 4, 512, 4608),
  1, &_conv4_conv_Conv_output_0_output_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  _conv4_Relu_output_0_output, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 9, 9), AI_STRIDE_INIT(4, 4, 4, 512, 4608),
  1, &_conv4_Relu_output_0_output_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_output, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 9, 9), AI_STRIDE_INIT(4, 4, 4, 4, 36),
  1, &_value_head_conv_conv_Conv_output_0_output_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_conv_Relu_output_0_output, AI_STATIC,
  223, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 9, 9), AI_STRIDE_INIT(4, 4, 4, 4, 36),
  1, &_value_head_conv_Relu_output_0_output_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_Flatten_output_0_to_chlast_output, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 9, 9, 1), AI_STRIDE_INIT(4, 4, 4, 36, 324),
  1, &_value_head_Flatten_output_0_to_chlast_output_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_Flatten_output_0_to_chlast_output0, AI_STATIC,
  225, 0x0,
  AI_SHAPE_INIT(4, 1, 81, 1, 1), AI_STRIDE_INIT(4, 4, 4, 324, 324),
  1, &_value_head_Flatten_output_0_to_chlast_output_array, NULL)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_output, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_value_head_fc_fc_0_Gemm_output_0_output_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_1_Relu_output_0_output, AI_STATIC,
  227, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_value_head_fc_fc_1_Relu_output_0_output_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_output, AI_STATIC,
  228, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &_value_head_fc_fc_2_Gemm_output_0_output_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  node_384_output, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &node_384_output_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_output, AI_STATIC,
  230, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 9, 9), AI_STRIDE_INIT(4, 4, 4, 8, 72),
  1, &_policy_head_conv_conv_Conv_output_0_output_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_conv_Relu_output_0_output, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 9, 9), AI_STRIDE_INIT(4, 4, 4, 8, 72),
  1, &_policy_head_conv_Relu_output_0_output_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_Flatten_output_0_to_chlast_output, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 9, 9, 2), AI_STRIDE_INIT(4, 4, 4, 36, 324),
  1, &_policy_head_Flatten_output_0_to_chlast_output_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_Flatten_output_0_to_chlast_output0, AI_STATIC,
  233, 0x0,
  AI_SHAPE_INIT(4, 1, 162, 1, 1), AI_STRIDE_INIT(4, 4, 4, 648, 648),
  1, &_policy_head_Flatten_output_0_to_chlast_output_array, NULL)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_output, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 81, 1, 1), AI_STRIDE_INIT(4, 4, 4, 324, 324),
  1, &_policy_head_fc_Gemm_output_0_output_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  output_softmax_output, AI_STATIC,
  235, 0x0,
  AI_SHAPE_INIT(4, 1, 81, 1, 1), AI_STRIDE_INIT(4, 4, 4, 324, 324),
  1, &output_softmax_output_array, NULL)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  output_output, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 81, 1, 1), AI_STRIDE_INIT(4, 4, 4, 324, 324),
  1, &output_output_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_weights, AI_STATIC,
  237, 0x0,
  AI_SHAPE_INIT(4, 6, 3, 3, 42), AI_STRIDE_INIT(4, 4, 24, 1008, 3024),
  1, &_conv1_conv_Conv_output_0_weights_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_bias, AI_STATIC,
  238, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_conv1_conv_Conv_output_0_bias_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_weights, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_0_conv1_Conv_output_0_weights_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_bias, AI_STATIC,
  240, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_0_conv1_Conv_output_0_bias_array, NULL)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_weights, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_0_conv2_Conv_output_0_weights_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_bias, AI_STATIC,
  242, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_0_conv2_Conv_output_0_bias_array, NULL)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_weights, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_1_conv1_Conv_output_0_weights_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_bias, AI_STATIC,
  244, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_1_conv1_Conv_output_0_bias_array, NULL)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_weights, AI_STATIC,
  245, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_1_conv2_Conv_output_0_weights_array, NULL)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_bias, AI_STATIC,
  246, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_1_conv2_Conv_output_0_bias_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_weights, AI_STATIC,
  247, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_2_conv1_Conv_output_0_weights_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_bias, AI_STATIC,
  248, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_2_conv1_Conv_output_0_bias_array, NULL)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_weights, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_2_conv2_Conv_output_0_weights_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_bias, AI_STATIC,
  250, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_2_conv2_Conv_output_0_bias_array, NULL)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_weights, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_3_conv1_Conv_output_0_weights_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_bias, AI_STATIC,
  252, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_3_conv1_Conv_output_0_bias_array, NULL)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_weights, AI_STATIC,
  253, 0x0,
  AI_SHAPE_INIT(4, 42, 3, 3, 42), AI_STRIDE_INIT(4, 4, 168, 7056, 21168),
  1, &_residues_residues_3_conv2_Conv_output_0_weights_array, NULL)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_bias, AI_STATIC,
  254, 0x0,
  AI_SHAPE_INIT(4, 1, 42, 1, 1), AI_STRIDE_INIT(4, 4, 4, 168, 168),
  1, &_residues_residues_3_conv2_Conv_output_0_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  output_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &output_softmax_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &output_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  output_layer, 131,
  NL_TYPE, 0x0, NULL,
  nl, forward_log,
  &output_chain,
  NULL, &output_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  output_softmax_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_fc_Gemm_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &output_softmax_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  output_softmax_layer, 130,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &output_softmax_chain,
  NULL, &output_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_Flatten_output_0_to_chlast_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_fc_Gemm_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_policy_head_fc_Gemm_output_0_weights, &_policy_head_fc_Gemm_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _policy_head_fc_Gemm_output_0_layer, 129,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &_policy_head_fc_Gemm_output_0_chain,
  NULL, &output_softmax_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _policy_head_Flatten_output_0_to_chlast_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_conv_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_Flatten_output_0_to_chlast_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _policy_head_Flatten_output_0_to_chlast_layer, 128,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &_policy_head_Flatten_output_0_to_chlast_chain,
  NULL, &_policy_head_fc_Gemm_output_0_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _policy_head_conv_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_conv_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_conv_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _policy_head_conv_Relu_output_0_layer, 127,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_policy_head_conv_Relu_output_0_chain,
  NULL, &_policy_head_Flatten_output_0_to_chlast_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv4_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_policy_head_conv_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_policy_head_conv_conv_Conv_output_0_weights, &_policy_head_conv_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _policy_head_conv_conv_Conv_output_0_layer, 126,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_policy_head_conv_conv_Conv_output_0_chain,
  NULL, &_policy_head_conv_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_384_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_fc_fc_2_Gemm_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_384_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_384_layer, 137,
  NL_TYPE, 0x0, NULL,
  nl, forward_tanh,
  &node_384_chain,
  NULL, &_policy_head_conv_conv_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_fc_fc_1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_fc_fc_2_Gemm_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_value_head_fc_fc_2_Gemm_output_0_weights, &_value_head_fc_fc_2_Gemm_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _value_head_fc_fc_2_Gemm_output_0_layer, 136,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &_value_head_fc_fc_2_Gemm_output_0_chain,
  NULL, &node_384_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _value_head_fc_fc_1_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_fc_fc_0_Gemm_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_fc_fc_1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _value_head_fc_fc_1_Relu_output_0_layer, 135,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_value_head_fc_fc_1_Relu_output_0_chain,
  NULL, &_value_head_fc_fc_2_Gemm_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_Flatten_output_0_to_chlast_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_fc_fc_0_Gemm_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_value_head_fc_fc_0_Gemm_output_0_weights, &_value_head_fc_fc_0_Gemm_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _value_head_fc_fc_0_Gemm_output_0_layer, 134,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &_value_head_fc_fc_0_Gemm_output_0_chain,
  NULL, &_value_head_fc_fc_1_Relu_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _value_head_Flatten_output_0_to_chlast_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_conv_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_Flatten_output_0_to_chlast_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _value_head_Flatten_output_0_to_chlast_layer, 133,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &_value_head_Flatten_output_0_to_chlast_chain,
  NULL, &_value_head_fc_fc_0_Gemm_output_0_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _value_head_conv_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_conv_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_conv_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _value_head_conv_Relu_output_0_layer, 132,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_value_head_conv_Relu_output_0_chain,
  NULL, &_value_head_Flatten_output_0_to_chlast_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv4_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_value_head_conv_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_value_head_conv_conv_Conv_output_0_weights, &_value_head_conv_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _value_head_conv_conv_Conv_output_0_layer, 131,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_value_head_conv_conv_Conv_output_0_chain,
  NULL, &_value_head_conv_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv4_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv4_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv4_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv4_Relu_output_0_layer, 125,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_conv4_Relu_output_0_chain,
  NULL, &_value_head_conv_conv_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv4_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_conv4_conv_Conv_output_0_weights, &_conv4_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv4_conv_Conv_output_0_layer, 124,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_conv4_conv_Conv_output_0_chain,
  NULL, &_conv4_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _Concat_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_residues_residues_3_Relu_1_output_0_output, &_conv3_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _Concat_output_0_layer, 123,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &_Concat_output_0_chain,
  NULL, &_conv4_conv_Conv_output_0_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv3_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv3_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv3_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv3_Relu_output_0_layer, 122,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_conv3_Relu_output_0_chain,
  NULL, &_Concat_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv3_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_conv3_conv_Conv_output_0_weights, &_conv3_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv3_conv_Conv_output_0_layer, 121,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_conv3_conv_Conv_output_0_chain,
  NULL, &_conv3_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 2, 2, 2, 2), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_act_Mul_1_output_0_scale, &_ULite_d1_act_Mul_1_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_act_Mul_1_output_0_layer, 120,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_d1_act_Mul_1_output_0_chain,
  NULL, &_conv3_conv_Conv_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_pw2_Conv_output_0_output, &_ULite_d1_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_act_Mul_output_0_layer, 119,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d1_act_Mul_output_0_chain,
  NULL, &_ULite_d1_act_Mul_1_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_act_Add_output_0_scale, &_ULite_d1_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_act_Add_output_0_layer, 118,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_d1_act_Add_output_0_chain,
  NULL, &_ULite_d1_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_act_Erf_output_0_layer, 117,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_d1_act_Erf_output_0_chain,
  NULL, &_ULite_d1_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_pw2_Conv_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_act_Div_output_0_layer, 116,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d1_act_Div_output_0_chain,
  NULL, &_ULite_d1_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_pw2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d1_pw2_Conv_output_0_weights, &_ULite_d1_pw2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_pw2_Conv_output_0_layer, 115,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_d1_pw2_Conv_output_0_chain,
  NULL, &_ULite_d1_act_Div_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_dw_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_dw_Add_output_0_output, &_ULite_d1_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_dw_Add_1_output_0_layer, 114,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d1_dw_Add_1_output_0_chain,
  NULL, &_ULite_d1_pw2_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_dw_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_pw_Conv_output_0_output, &_ULite_d1_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_dw_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_dw_Add_output_0_layer, 112,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d1_dw_Add_output_0_chain,
  NULL, &_ULite_d1_dw_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d1_dw_dw_h_Conv_output_0_weights, &_ULite_d1_dw_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_dw_dw_h_Conv_output_0_layer, 111,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_d1_dw_dw_h_Conv_output_0_chain,
  NULL, &_ULite_d1_dw_Add_output_0_layer, AI_STATIC, 
  .groups = 16, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d1_dw_dw_w_Conv_output_0_weights, &_ULite_d1_dw_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_dw_dw_w_Conv_output_0_layer, 113,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_d1_dw_dw_w_Conv_output_0_chain,
  NULL, &_ULite_d1_dw_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 16, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d1_pw_Conv_output_0_weights, &_ULite_d1_pw_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_pw_Conv_output_0_layer, 110,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_d1_pw_Conv_output_0_chain,
  NULL, &_ULite_d1_dw_dw_w_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_Concat_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d1_up_Resize_output_0_output, &_ULite_e1_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_Concat_output_0_layer, 109,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &_ULite_d1_Concat_output_0_chain,
  NULL, &_ULite_d1_pw_Conv_output_0_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_float _ULite_d1_up_Resize_output_0_scales_data[] = { 2.0, 2.0, 1, 1 };
AI_ARRAY_OBJ_DECLARE(
    _ULite_d1_up_Resize_output_0_scales, AI_ARRAY_FORMAT_FLOAT,
    _ULite_d1_up_Resize_output_0_scales_data, _ULite_d1_up_Resize_output_0_scales_data, 4, AI_STATIC_CONST)

AI_STATIC_CONST ai_float _ULite_d1_up_Resize_output_0_roi_data[] = { 0, 0, 0, 1, 1, 1 };
AI_ARRAY_OBJ_DECLARE(
    _ULite_d1_up_Resize_output_0_roi, AI_ARRAY_FORMAT_FLOAT,
    _ULite_d1_up_Resize_output_0_roi_data, _ULite_d1_up_Resize_output_0_roi_data, 6, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d1_up_Resize_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d1_up_Resize_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d1_up_Resize_output_0_layer, 108,
  RESIZE_TYPE, 0x0, NULL,
  resize, forward_resize_if32of32,
  &_ULite_d1_up_Resize_output_0_chain,
  NULL, &_ULite_d1_Concat_output_0_layer, AI_STATIC, 
  .scales = &_ULite_d1_up_Resize_output_0_scales, 
  .roi = &_ULite_d1_up_Resize_output_0_roi, 
  .coord_transf_mode = AI_ASYMMETRIC, 
  .cubic_coeff_a = -0.75, 
  .exclude_outside = 0, 
  .extrapol_val = 0.0, 
  .mode = AI_RESIZE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_act_Mul_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_act_Mul_1_output_0_scale, &_ULite_e1_act_Mul_1_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_act_Mul_1_output_0_layer, 107,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_d2_act_Mul_1_output_0_chain,
  NULL, &_ULite_d1_up_Resize_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d2_pw2_Conv_output_0_output, &_ULite_d2_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_act_Mul_output_0_layer, 106,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d2_act_Mul_output_0_chain,
  NULL, &_ULite_d2_act_Mul_1_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_act_Add_output_0_scale, &_ULite_e1_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_act_Add_output_0_layer, 105,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_d2_act_Add_output_0_chain,
  NULL, &_ULite_d2_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_act_Erf_output_0_layer, 104,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_d2_act_Erf_output_0_chain,
  NULL, &_ULite_d2_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d2_pw2_Conv_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_act_Div_output_0_layer, 103,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d2_act_Div_output_0_chain,
  NULL, &_ULite_d2_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_pw2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d2_pw2_Conv_output_0_weights, &_ULite_d2_pw2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_pw2_Conv_output_0_layer, 102,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_d2_pw2_Conv_output_0_chain,
  NULL, &_ULite_d2_act_Div_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_dw_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d2_dw_Add_output_0_output, &_ULite_d2_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_dw_Add_1_output_0_layer, 101,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d2_dw_Add_1_output_0_chain,
  NULL, &_ULite_d2_pw2_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_dw_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d2_pw_Conv_output_0_output, &_ULite_d2_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_dw_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_dw_Add_output_0_layer, 99,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d2_dw_Add_output_0_chain,
  NULL, &_ULite_d2_dw_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d2_dw_dw_h_Conv_output_0_weights, &_ULite_d2_dw_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_dw_dw_h_Conv_output_0_layer, 98,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_d2_dw_dw_h_Conv_output_0_chain,
  NULL, &_ULite_d2_dw_Add_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d2_dw_dw_w_Conv_output_0_weights, &_ULite_d2_dw_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_dw_dw_w_Conv_output_0_layer, 100,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_d2_dw_dw_w_Conv_output_0_chain,
  NULL, &_ULite_d2_dw_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d2_pw_Conv_output_0_weights, &_ULite_d2_pw_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_pw_Conv_output_0_layer, 97,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_d2_pw_Conv_output_0_chain,
  NULL, &_ULite_d2_dw_dw_w_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_Concat_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d2_up_Resize_output_0_output, &_ULite_e2_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_Concat_output_0_layer, 96,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &_ULite_d2_Concat_output_0_chain,
  NULL, &_ULite_d2_pw_Conv_output_0_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_float _ULite_d2_up_Resize_output_0_scales_data[] = { 2.0, 2.0, 1, 1 };
AI_ARRAY_OBJ_DECLARE(
    _ULite_d2_up_Resize_output_0_scales, AI_ARRAY_FORMAT_FLOAT,
    _ULite_d2_up_Resize_output_0_scales_data, _ULite_d2_up_Resize_output_0_scales_data, 4, AI_STATIC_CONST)

AI_STATIC_CONST ai_float _ULite_d2_up_Resize_output_0_roi_data[] = { 0, 0, 0, 1, 1, 1 };
AI_ARRAY_OBJ_DECLARE(
    _ULite_d2_up_Resize_output_0_roi, AI_ARRAY_FORMAT_FLOAT,
    _ULite_d2_up_Resize_output_0_roi_data, _ULite_d2_up_Resize_output_0_roi_data, 6, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d2_up_Resize_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d2_up_Resize_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d2_up_Resize_output_0_layer, 95,
  RESIZE_TYPE, 0x0, NULL,
  resize, forward_resize_if32of32,
  &_ULite_d2_up_Resize_output_0_chain,
  NULL, &_ULite_d2_Concat_output_0_layer, AI_STATIC, 
  .scales = &_ULite_d2_up_Resize_output_0_scales, 
  .roi = &_ULite_d2_up_Resize_output_0_roi, 
  .coord_transf_mode = AI_ASYMMETRIC, 
  .cubic_coeff_a = -0.75, 
  .exclude_outside = 0, 
  .extrapol_val = 0.0, 
  .mode = AI_RESIZE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_act_Mul_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_act_Mul_1_output_0_scale, &_ULite_e2_act_Mul_1_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_act_Mul_1_output_0_layer, 94,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_d3_act_Mul_1_output_0_chain,
  NULL, &_ULite_d2_up_Resize_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d3_pw2_Conv_output_0_output, &_ULite_d3_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_act_Mul_output_0_layer, 93,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d3_act_Mul_output_0_chain,
  NULL, &_ULite_d3_act_Mul_1_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_act_Add_output_0_scale, &_ULite_e2_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_act_Add_output_0_layer, 92,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_d3_act_Add_output_0_chain,
  NULL, &_ULite_d3_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_act_Erf_output_0_layer, 91,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_d3_act_Erf_output_0_chain,
  NULL, &_ULite_d3_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d3_pw2_Conv_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_act_Div_output_0_layer, 90,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d3_act_Div_output_0_chain,
  NULL, &_ULite_d3_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_pw2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d3_pw2_Conv_output_0_weights, &_ULite_d3_pw2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_pw2_Conv_output_0_layer, 89,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_d3_pw2_Conv_output_0_chain,
  NULL, &_ULite_d3_act_Div_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_dw_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d3_dw_Add_output_0_output, &_ULite_d3_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_dw_Add_1_output_0_layer, 88,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d3_dw_Add_1_output_0_chain,
  NULL, &_ULite_d3_pw2_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_dw_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d3_pw_Conv_output_0_output, &_ULite_d3_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_dw_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_dw_Add_output_0_layer, 86,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_d3_dw_Add_output_0_chain,
  NULL, &_ULite_d3_dw_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d3_dw_dw_h_Conv_output_0_weights, &_ULite_d3_dw_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_dw_dw_h_Conv_output_0_layer, 85,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_d3_dw_dw_h_Conv_output_0_chain,
  NULL, &_ULite_d3_dw_Add_output_0_layer, AI_STATIC, 
  .groups = 64, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d3_dw_dw_w_Conv_output_0_weights, &_ULite_d3_dw_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_dw_dw_w_Conv_output_0_layer, 87,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_d3_dw_dw_w_Conv_output_0_chain,
  NULL, &_ULite_d3_dw_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 64, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_d3_pw_Conv_output_0_weights, &_ULite_d3_pw_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_pw_Conv_output_0_layer, 84,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_d3_pw_Conv_output_0_chain,
  NULL, &_ULite_d3_dw_dw_w_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_Concat_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_d3_up_Resize_output_0_output, &_ULite_e3_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_Concat_output_0_layer, 83,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &_ULite_d3_Concat_output_0_chain,
  NULL, &_ULite_d3_pw_Conv_output_0_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_float _ULite_d3_up_Resize_output_0_scales_data[] = { 2.0, 2.0, 1, 1 };
AI_ARRAY_OBJ_DECLARE(
    _ULite_d3_up_Resize_output_0_scales, AI_ARRAY_FORMAT_FLOAT,
    _ULite_d3_up_Resize_output_0_scales_data, _ULite_d3_up_Resize_output_0_scales_data, 4, AI_STATIC_CONST)

AI_STATIC_CONST ai_float _ULite_d3_up_Resize_output_0_roi_data[] = { 0, 0, 0, 1, 1, 1 };
AI_ARRAY_OBJ_DECLARE(
    _ULite_d3_up_Resize_output_0_roi, AI_ARRAY_FORMAT_FLOAT,
    _ULite_d3_up_Resize_output_0_roi_data, _ULite_d3_up_Resize_output_0_roi_data, 6, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_d3_up_Resize_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_d3_up_Resize_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_d3_up_Resize_output_0_layer, 82,
  RESIZE_TYPE, 0x0, NULL,
  resize, forward_resize_if32of32,
  &_ULite_d3_up_Resize_output_0_chain,
  NULL, &_ULite_d3_Concat_output_0_layer, AI_STATIC, 
  .scales = &_ULite_d3_up_Resize_output_0_scales, 
  .roi = &_ULite_d3_up_Resize_output_0_roi, 
  .coord_transf_mode = AI_ASYMMETRIC, 
  .cubic_coeff_a = -0.75, 
  .exclude_outside = 0, 
  .extrapol_val = 0.0, 
  .mode = AI_RESIZE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_act_Mul_1_output_0_scale, &_ULite_b5_act_Mul_1_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_act_Mul_1_output_0_layer, 81,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_b5_act_Mul_1_output_0_chain,
  NULL, &_ULite_d3_up_Resize_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_pw2_Conv_output_0_output, &_ULite_b5_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_act_Mul_output_0_layer, 80,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_act_Mul_output_0_chain,
  NULL, &_ULite_b5_act_Mul_1_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e3_act_Add_output_0_scale, &_ULite_e3_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_act_Add_output_0_layer, 79,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_b5_act_Add_output_0_chain,
  NULL, &_ULite_b5_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_act_Erf_output_0_layer, 78,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_b5_act_Erf_output_0_chain,
  NULL, &_ULite_b5_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_pw2_Conv_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_act_Div_output_0_layer, 77,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_act_Div_output_0_chain,
  NULL, &_ULite_b5_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_pw2_Conv_output_0_weights, &_ULite_b5_pw2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_pw2_Conv_output_0_layer, 76,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_b5_pw2_Conv_output_0_chain,
  NULL, &_ULite_b5_act_Div_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_Concat_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 4, &_ULite_b5_pw1_Conv_output_0_output, &_ULite_b5_dw1_Add_1_output_0_output, &_ULite_b5_dw2_Add_1_output_0_output, &_ULite_b5_dw3_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_Concat_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_Concat_output_0_layer, 74,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &_ULite_b5_Concat_output_0_chain,
  NULL, &_ULite_b5_pw2_Conv_output_0_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw1_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_dw1_Add_output_0_output, &_ULite_b5_dw1_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw1_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw1_Add_1_output_0_layer, 65,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_dw1_Add_1_output_0_chain,
  NULL, &_ULite_b5_Concat_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw1_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_pw1_Conv_output_0_output, &_ULite_b5_dw1_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw1_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw1_Add_output_0_layer, 63,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_dw1_Add_output_0_chain,
  NULL, &_ULite_b5_dw1_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw1_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_dw1_dw_h_Conv_output_0_weights, &_ULite_b5_dw1_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw1_dw_h_Conv_output_0_layer, 62,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_b5_dw1_dw_h_Conv_output_0_chain,
  NULL, &_ULite_b5_dw1_Add_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 0, 1, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw1_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_dw1_dw_w_Conv_output_0_weights, &_ULite_b5_dw1_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw1_dw_w_Conv_output_0_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_b5_dw1_dw_w_Conv_output_0_chain,
  NULL, &_ULite_b5_dw1_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 1, 0, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw2_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_dw2_Add_output_0_output, &_ULite_b5_dw2_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw2_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw2_Add_1_output_0_layer, 69,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_dw2_Add_1_output_0_chain,
  NULL, &_ULite_b5_dw1_dw_w_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw2_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_pw1_Conv_output_0_output, &_ULite_b5_dw2_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw2_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw2_Add_output_0_layer, 67,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_dw2_Add_output_0_chain,
  NULL, &_ULite_b5_dw2_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw2_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_dw2_dw_h_Conv_output_0_weights, &_ULite_b5_dw2_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw2_dw_h_Conv_output_0_layer, 66,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &_ULite_b5_dw2_dw_h_Conv_output_0_chain,
  NULL, &_ULite_b5_dw2_Add_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(2, 2), 
  .filter_pad = AI_SHAPE_INIT(4, 2, 0, 2, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw2_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_dw2_dw_w_Conv_output_0_weights, &_ULite_b5_dw2_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw2_dw_w_Conv_output_0_layer, 68,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &_ULite_b5_dw2_dw_w_Conv_output_0_chain,
  NULL, &_ULite_b5_dw2_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(2, 2), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 2, 0, 2), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw3_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_dw3_Add_output_0_output, &_ULite_b5_dw3_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw3_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw3_Add_1_output_0_layer, 73,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_dw3_Add_1_output_0_chain,
  NULL, &_ULite_b5_dw2_dw_w_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw3_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_b5_pw1_Conv_output_0_output, &_ULite_b5_dw3_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw3_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw3_Add_output_0_layer, 71,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_b5_dw3_Add_output_0_chain,
  NULL, &_ULite_b5_dw3_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw3_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_dw3_dw_h_Conv_output_0_weights, &_ULite_b5_dw3_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw3_dw_h_Conv_output_0_layer, 70,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &_ULite_b5_dw3_dw_h_Conv_output_0_chain,
  NULL, &_ULite_b5_dw3_Add_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(3, 3), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_dw3_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_dw3_dw_w_Conv_output_0_weights, &_ULite_b5_dw3_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_dw3_dw_w_Conv_output_0_layer, 72,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &_ULite_b5_dw3_dw_w_Conv_output_0_chain,
  NULL, &_ULite_b5_dw3_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(3, 3), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_b5_pw1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_b5_pw1_Conv_output_0_weights, &_ULite_b5_pw1_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_b5_pw1_Conv_output_0_layer, 61,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_b5_pw1_Conv_output_0_chain,
  NULL, &_ULite_b5_dw3_dw_w_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e3_down_MaxPool_output_0_output, &_ULite_e3_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_act_Mul_output_0_layer, 59,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e3_act_Mul_output_0_chain,
  NULL, &_ULite_b5_pw1_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e3_act_Add_output_0_scale, &_ULite_e3_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_act_Add_output_0_layer, 58,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e3_act_Add_output_0_chain,
  NULL, &_ULite_e3_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_act_Erf_output_0_layer, 57,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_e3_act_Erf_output_0_chain,
  NULL, &_ULite_e3_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e3_down_MaxPool_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_act_Div_output_0_layer, 56,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e3_act_Div_output_0_chain,
  NULL, &_ULite_e3_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_down_MaxPool_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_down_MaxPool_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_down_MaxPool_output_0_layer, 55,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp,
  &_ULite_e3_down_MaxPool_output_0_chain,
  NULL, &_ULite_e3_act_Div_output_0_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e3_pw_Conv_output_0_weights, &_ULite_e3_pw_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_pw_Conv_output_0_layer, 54,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_ULite_e3_pw_Conv_output_0_chain,
  NULL, &_ULite_e3_down_MaxPool_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e3_bn_BatchNormalization_output_0_scale, &_ULite_e3_bn_BatchNormalization_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_bn_BatchNormalization_output_0_layer, 53,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e3_bn_BatchNormalization_output_0_chain,
  NULL, &_ULite_e3_pw_Conv_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_dw_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e3_dw_Add_output_0_output, &_ULite_e3_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_dw_Add_1_output_0_layer, 52,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e3_dw_Add_1_output_0_chain,
  NULL, &_ULite_e3_bn_BatchNormalization_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_dw_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_act_Mul_1_output_0_output, &_ULite_e3_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_dw_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_dw_Add_output_0_layer, 50,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e3_dw_Add_output_0_chain,
  NULL, &_ULite_e3_dw_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e3_dw_dw_h_Conv_output_0_weights, &_ULite_e3_dw_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_dw_dw_h_Conv_output_0_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_e3_dw_dw_h_Conv_output_0_chain,
  NULL, &_ULite_e3_dw_Add_output_0_layer, AI_STATIC, 
  .groups = 64, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e3_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e3_dw_dw_w_Conv_output_0_weights, &_ULite_e3_dw_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e3_dw_dw_w_Conv_output_0_layer, 51,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_e3_dw_dw_w_Conv_output_0_chain,
  NULL, &_ULite_e3_dw_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 64, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_act_Mul_1_output_0_scale, &_ULite_e2_act_Mul_1_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_act_Mul_1_output_0_layer, 48,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e2_act_Mul_1_output_0_chain,
  NULL, &_ULite_e3_dw_dw_w_Conv_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_pw_Conv_output_0_output, &_ULite_e2_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_act_Mul_output_0_layer, 47,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e2_act_Mul_output_0_chain,
  NULL, &_ULite_e2_act_Mul_1_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_act_Add_output_0_scale, &_ULite_e2_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_act_Add_output_0_layer, 46,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e2_act_Add_output_0_chain,
  NULL, &_ULite_e2_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_act_Erf_output_0_layer, 45,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_e2_act_Erf_output_0_chain,
  NULL, &_ULite_e2_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_pw_Conv_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_act_Div_output_0_layer, 44,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e2_act_Div_output_0_chain,
  NULL, &_ULite_e2_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e2_pw_Conv_output_0_weights, &_ULite_e2_pw_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_pw_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_pw_Conv_output_0_layer, 43,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_if32of32wf32_nl_pool,
  &_ULite_e2_pw_Conv_output_0_chain,
  NULL, &_ULite_e2_act_Div_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_f32), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_bn_BatchNormalization_output_0_scale, &_ULite_e2_bn_BatchNormalization_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_bn_BatchNormalization_output_0_layer, 41,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e2_bn_BatchNormalization_output_0_chain,
  NULL, &_ULite_e2_pw_Conv_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_dw_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e2_dw_Add_output_0_output, &_ULite_e2_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_dw_Add_1_output_0_layer, 40,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e2_dw_Add_1_output_0_chain,
  NULL, &_ULite_e2_bn_BatchNormalization_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_dw_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_act_Mul_1_output_0_output, &_ULite_e2_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_dw_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_dw_Add_output_0_layer, 38,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e2_dw_Add_output_0_chain,
  NULL, &_ULite_e2_dw_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e2_dw_dw_h_Conv_output_0_weights, &_ULite_e2_dw_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_dw_dw_h_Conv_output_0_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_e2_dw_dw_h_Conv_output_0_chain,
  NULL, &_ULite_e2_dw_Add_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e2_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e2_dw_dw_w_Conv_output_0_weights, &_ULite_e2_dw_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e2_dw_dw_w_Conv_output_0_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_e2_dw_dw_w_Conv_output_0_chain,
  NULL, &_ULite_e2_dw_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Mul_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_act_Mul_1_output_0_scale, &_ULite_e1_act_Mul_1_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_act_Mul_1_output_0_layer, 36,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e1_act_Mul_1_output_0_chain,
  NULL, &_ULite_e2_dw_dw_w_Conv_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_act_Mul_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_pw_Conv_output_0_output, &_ULite_e1_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Mul_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_act_Mul_output_0_layer, 35,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e1_act_Mul_output_0_chain,
  NULL, &_ULite_e1_act_Mul_1_output_0_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_act_Add_output_0_scale, &_ULite_e1_act_Add_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_act_Add_output_0_layer, 34,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e1_act_Add_output_0_chain,
  NULL, &_ULite_e1_act_Mul_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_act_Erf_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Erf_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_act_Erf_output_0_layer, 33,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &_ULite_e1_act_Erf_output_0_chain,
  NULL, &_ULite_e1_act_Add_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_act_Div_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_pw_Conv_output_0_output, &_ULite_e1_act_Constant_output_0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_act_Div_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_act_Div_output_0_layer, 32,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e1_act_Div_output_0_chain,
  NULL, &_ULite_e1_act_Erf_output_0_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_pw_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e1_pw_Conv_output_0_weights, &_ULite_e1_pw_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_pw_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_pw_Conv_output_0_layer, 31,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_if32of32wf32_nl_pool,
  &_ULite_e1_pw_Conv_output_0_chain,
  NULL, &_ULite_e1_act_Div_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_f32), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_bn_BatchNormalization_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_bn_BatchNormalization_output_0_scale, &_ULite_e1_bn_BatchNormalization_output_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_bn_BatchNormalization_output_0_layer, 29,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &_ULite_e1_bn_BatchNormalization_output_0_chain,
  NULL, &_ULite_e1_pw_Conv_output_0_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_dw_Add_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_ULite_e1_dw_Add_output_0_output, &_ULite_e1_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_dw_Add_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_dw_Add_1_output_0_layer, 28,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e1_dw_Add_1_output_0_chain,
  NULL, &_ULite_e1_bn_BatchNormalization_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_dw_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_conv2_Relu_output_0_output, &_ULite_e1_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_dw_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_dw_Add_output_0_layer, 26,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_ULite_e1_dw_Add_output_0_chain,
  NULL, &_ULite_e1_dw_Add_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_dw_dw_h_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e1_dw_dw_h_Conv_output_0_weights, &_ULite_e1_dw_dw_h_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_dw_dw_h_Conv_output_0_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_e1_dw_dw_h_Conv_output_0_chain,
  NULL, &_ULite_e1_dw_Add_output_0_layer, AI_STATIC, 
  .groups = 16, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_ULite_e1_dw_dw_w_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_ULite_e1_dw_dw_w_Conv_output_0_weights, &_ULite_e1_dw_dw_w_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _ULite_e1_dw_dw_w_Conv_output_0_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &_ULite_e1_dw_dw_w_Conv_output_0_chain,
  NULL, &_ULite_e1_dw_dw_h_Conv_output_0_layer, AI_STATIC, 
  .groups = 16, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 3, 0, 3), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv2_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv2_Relu_output_0_layer, 4,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_conv2_Relu_output_0_chain,
  NULL, &_ULite_e1_dw_dw_w_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_conv2_conv_Conv_output_0_weights, &_conv2_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_conv2_conv_Conv_output_0_chain,
  NULL, &_conv2_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_3_Relu_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_3_Relu_1_output_0_layer, 24,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_3_Relu_1_output_0_chain,
  NULL, &_conv2_conv_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_3_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_residues_residues_3_conv2_Conv_output_0_output, &_residues_residues_2_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_3_Add_output_0_layer, 23,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_residues_residues_3_Add_output_0_chain,
  NULL, &_residues_residues_3_Relu_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_conv2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_3_conv2_Conv_output_0_weights, &_residues_residues_3_conv2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_3_conv2_Conv_output_0_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_3_conv2_Conv_output_0_chain,
  NULL, &_residues_residues_3_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_3_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_3_Relu_output_0_layer, 21,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_3_Relu_output_0_chain,
  NULL, &_residues_residues_3_conv2_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_3_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_3_conv1_Conv_output_0_weights, &_residues_residues_3_conv1_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_3_conv1_Conv_output_0_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_3_conv1_Conv_output_0_chain,
  NULL, &_residues_residues_3_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_2_Relu_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_2_Relu_1_output_0_layer, 19,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_2_Relu_1_output_0_chain,
  NULL, &_residues_residues_3_conv1_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_2_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_residues_residues_2_conv2_Conv_output_0_output, &_residues_residues_1_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_2_Add_output_0_layer, 18,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_residues_residues_2_Add_output_0_chain,
  NULL, &_residues_residues_2_Relu_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_conv2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_2_conv2_Conv_output_0_weights, &_residues_residues_2_conv2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_2_conv2_Conv_output_0_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_2_conv2_Conv_output_0_chain,
  NULL, &_residues_residues_2_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_2_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_2_Relu_output_0_layer, 16,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_2_Relu_output_0_chain,
  NULL, &_residues_residues_2_conv2_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_2_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_2_conv1_Conv_output_0_weights, &_residues_residues_2_conv1_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_2_conv1_Conv_output_0_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_2_conv1_Conv_output_0_chain,
  NULL, &_residues_residues_2_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_1_Relu_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_1_Relu_1_output_0_layer, 14,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_1_Relu_1_output_0_chain,
  NULL, &_residues_residues_2_conv1_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_1_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_residues_residues_1_conv2_Conv_output_0_output, &_residues_residues_0_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_1_Add_output_0_layer, 13,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_residues_residues_1_Add_output_0_chain,
  NULL, &_residues_residues_1_Relu_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_conv2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_1_conv2_Conv_output_0_weights, &_residues_residues_1_conv2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_1_conv2_Conv_output_0_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_1_conv2_Conv_output_0_chain,
  NULL, &_residues_residues_1_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_1_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_1_Relu_output_0_layer, 11,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_1_Relu_output_0_chain,
  NULL, &_residues_residues_1_conv2_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_1_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_1_conv1_Conv_output_0_weights, &_residues_residues_1_conv1_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_1_conv1_Conv_output_0_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_1_conv1_Conv_output_0_chain,
  NULL, &_residues_residues_1_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_0_Relu_1_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_Relu_1_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_0_Relu_1_output_0_layer, 9,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_0_Relu_1_output_0_chain,
  NULL, &_residues_residues_1_conv1_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_0_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_residues_residues_0_conv2_Conv_output_0_output, &_conv1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_0_Add_output_0_layer, 8,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &_residues_residues_0_Add_output_0_chain,
  NULL, &_residues_residues_0_Relu_1_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_conv2_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_0_conv2_Conv_output_0_weights, &_residues_residues_0_conv2_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_0_conv2_Conv_output_0_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_0_conv2_Conv_output_0_chain,
  NULL, &_residues_residues_0_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_0_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_0_Relu_output_0_layer, 6,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_residues_residues_0_Relu_output_0_chain,
  NULL, &_residues_residues_0_conv2_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_residues_residues_0_conv1_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_residues_residues_0_conv1_Conv_output_0_weights, &_residues_residues_0_conv1_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _residues_residues_0_conv1_Conv_output_0_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_residues_residues_0_conv1_Conv_output_0_chain,
  NULL, &_residues_residues_0_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv1_Relu_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_Relu_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv1_Relu_output_0_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &_conv1_Relu_output_0_chain,
  NULL, &_residues_residues_0_conv1_Conv_output_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_Transpose_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_conv1_conv_Conv_output_0_weights, &_conv1_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &_conv1_conv_Conv_output_0_chain,
  NULL, &_conv1_Relu_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  input_Transpose_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_Transpose_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  input_Transpose_layer, 2,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &input_Transpose_chain,
  NULL, &_conv1_conv_Conv_output_0_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1268472, 1, 1),
    1268472, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 57408, 1, 1),
    57408, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &output_output, &node_384_output),
  &input_Transpose_layer, 0xfa430150, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1268472, 1, 1),
      1268472, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 57408, 1, 1),
      57408, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &output_output, &node_384_output),
  &input_Transpose_layer, 0xfa430150, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_output_array.data = AI_PTR(g_network_activations_map[0] + 14640);
    input_output_array.data_start = AI_PTR(g_network_activations_map[0] + 14640);
    input_Transpose_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    input_Transpose_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _conv1_conv_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _conv1_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _conv1_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _conv1_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _residues_residues_0_conv1_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_0_conv1_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_0_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_0_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_0_conv2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_0_conv2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_0_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_0_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_0_Relu_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_0_Relu_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_1_conv1_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_1_conv1_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_1_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_1_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_1_conv2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_1_conv2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_1_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_1_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_1_Relu_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_1_Relu_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_2_conv1_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_2_conv1_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_2_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_2_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_2_conv2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_2_conv2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_2_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_2_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_2_Relu_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_2_Relu_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_3_conv1_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_3_conv1_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_3_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_3_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_3_conv2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_3_conv2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _residues_residues_3_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_3_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 43800);
    _residues_residues_3_Relu_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 16584);
    _residues_residues_3_Relu_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16584);
    _conv2_conv_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _conv2_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _conv2_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _conv2_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_dw_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_e1_dw_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_e1_dw_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e1_dw_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e1_dw_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_e1_dw_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_e1_dw_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_dw_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_bn_BatchNormalization_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_e1_bn_BatchNormalization_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_e1_pw_Conv_output_0_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_pw_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_pw_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_e1_pw_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_e1_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e1_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e1_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e1_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e1_act_Mul_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e1_act_Mul_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_dw_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_e2_dw_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_e2_dw_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e2_dw_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e2_dw_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 13216);
    _ULite_e2_dw_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 13216);
    _ULite_e2_dw_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_dw_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_bn_BatchNormalization_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_e2_bn_BatchNormalization_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_e2_pw_Conv_output_0_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_pw_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_pw_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e2_pw_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e2_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e2_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e2_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e2_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e2_act_Mul_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e2_act_Mul_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e3_dw_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e3_dw_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e3_dw_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_dw_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_dw_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 12192);
    _ULite_e3_dw_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12192);
    _ULite_e3_dw_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e3_dw_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e3_bn_BatchNormalization_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e3_bn_BatchNormalization_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_e3_pw_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_pw_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_down_MaxPool_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e3_down_MaxPool_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_e3_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_e3_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_e3_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_e3_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_e3_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_e3_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_pw1_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_b5_pw1_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_b5_dw3_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3104);
    _ULite_b5_dw3_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3104);
    _ULite_b5_dw3_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3232);
    _ULite_b5_dw3_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3232);
    _ULite_b5_dw3_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3360);
    _ULite_b5_dw3_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3360);
    _ULite_b5_dw3_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3232);
    _ULite_b5_dw3_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3232);
    _ULite_b5_dw2_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3104);
    _ULite_b5_dw2_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3104);
    _ULite_b5_dw2_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3360);
    _ULite_b5_dw2_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3360);
    _ULite_b5_dw2_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_dw2_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_dw2_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3360);
    _ULite_b5_dw2_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3360);
    _ULite_b5_dw1_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3104);
    _ULite_b5_dw1_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3104);
    _ULite_b5_dw1_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_dw1_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_dw1_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3616);
    _ULite_b5_dw1_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3616);
    _ULite_b5_dw1_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_dw1_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_Concat_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_Concat_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_pw2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_b5_pw2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_b5_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3488);
    _ULite_b5_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_b5_act_Mul_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_b5_act_Mul_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_up_Resize_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_up_Resize_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_Concat_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 13216);
    _ULite_d3_Concat_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 13216);
    _ULite_d3_pw_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_pw_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_dw_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_d3_dw_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_d3_dw_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_dw_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_dw_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 12192);
    _ULite_d3_dw_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12192);
    _ULite_d3_dw_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_dw_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_pw2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_d3_pw2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4000);
    _ULite_d3_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d3_act_Mul_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d3_act_Mul_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_up_Resize_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_up_Resize_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_Concat_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_d2_Concat_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_d2_pw_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_pw_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_dw_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_d2_dw_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_d2_dw_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_dw_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_dw_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 13216);
    _ULite_d2_dw_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 13216);
    _ULite_d2_dw_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_dw_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_pw2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_d2_pw2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5024);
    _ULite_d2_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d2_act_Mul_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d2_act_Mul_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_up_Resize_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_d1_up_Resize_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_d1_Concat_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 38384);
    _ULite_d1_Concat_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 38384);
    _ULite_d1_pw_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_pw_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_dw_dw_w_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_d1_dw_dw_w_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_d1_dw_dw_h_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d1_dw_dw_h_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d1_dw_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_d1_dw_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _ULite_d1_dw_Add_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_dw_Add_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_pw2_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_d1_pw2_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 7072);
    _ULite_d1_act_Div_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_act_Div_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_act_Erf_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d1_act_Erf_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d1_act_Add_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_act_Add_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_act_Mul_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d1_act_Mul_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11168);
    _ULite_d1_act_Mul_1_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _ULite_d1_act_Mul_1_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _conv3_conv_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _conv3_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _conv3_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    _conv3_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    _Concat_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 30192);
    _Concat_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30192);
    _conv4_conv_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    _conv4_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    _conv4_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    _conv4_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    _value_head_conv_conv_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 41472);
    _value_head_conv_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41472);
    _value_head_conv_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 41796);
    _value_head_conv_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41796);
    _value_head_Flatten_output_0_to_chlast_output_array.data = AI_PTR(g_network_activations_map[0] + 41472);
    _value_head_Flatten_output_0_to_chlast_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41472);
    _value_head_fc_fc_0_Gemm_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 41796);
    _value_head_fc_fc_0_Gemm_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41796);
    _value_head_fc_fc_1_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 42308);
    _value_head_fc_fc_1_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 42308);
    _value_head_fc_fc_2_Gemm_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 41472);
    _value_head_fc_fc_2_Gemm_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41472);
    node_384_output_array.data = AI_PTR(g_network_activations_map[0] + 41476);
    node_384_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41476);
    _policy_head_conv_conv_Conv_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 41480);
    _policy_head_conv_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 41480);
    _policy_head_conv_Relu_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    _policy_head_conv_Relu_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    _policy_head_Flatten_output_0_to_chlast_output_array.data = AI_PTR(g_network_activations_map[0] + 648);
    _policy_head_Flatten_output_0_to_chlast_output_array.data_start = AI_PTR(g_network_activations_map[0] + 648);
    _policy_head_fc_Gemm_output_0_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    _policy_head_fc_Gemm_output_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    output_softmax_output_array.data = AI_PTR(g_network_activations_map[0] + 324);
    output_softmax_output_array.data_start = AI_PTR(g_network_activations_map[0] + 324);
    output_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    output_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    _conv1_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _conv1_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 0);
    _conv1_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 0);
    _conv1_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _conv1_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 9072);
    _conv1_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 9072);
    _residues_residues_0_conv1_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_0_conv1_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 9240);
    _residues_residues_0_conv1_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 9240);
    _residues_residues_0_conv1_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_0_conv1_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 72744);
    _residues_residues_0_conv1_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 72744);
    _residues_residues_0_conv2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_0_conv2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 72912);
    _residues_residues_0_conv2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 72912);
    _residues_residues_0_conv2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_0_conv2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 136416);
    _residues_residues_0_conv2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 136416);
    _residues_residues_1_conv1_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_1_conv1_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 136584);
    _residues_residues_1_conv1_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 136584);
    _residues_residues_1_conv1_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_1_conv1_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 200088);
    _residues_residues_1_conv1_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 200088);
    _residues_residues_1_conv2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_1_conv2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 200256);
    _residues_residues_1_conv2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 200256);
    _residues_residues_1_conv2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_1_conv2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 263760);
    _residues_residues_1_conv2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 263760);
    _residues_residues_2_conv1_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_2_conv1_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 263928);
    _residues_residues_2_conv1_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 263928);
    _residues_residues_2_conv1_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_2_conv1_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 327432);
    _residues_residues_2_conv1_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 327432);
    _residues_residues_2_conv2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_2_conv2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 327600);
    _residues_residues_2_conv2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 327600);
    _residues_residues_2_conv2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_2_conv2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 391104);
    _residues_residues_2_conv2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 391104);
    _residues_residues_3_conv1_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_3_conv1_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 391272);
    _residues_residues_3_conv1_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 391272);
    _residues_residues_3_conv1_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_3_conv1_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 454776);
    _residues_residues_3_conv1_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 454776);
    _residues_residues_3_conv2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_3_conv2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 454944);
    _residues_residues_3_conv2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 454944);
    _residues_residues_3_conv2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _residues_residues_3_conv2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 518448);
    _residues_residues_3_conv2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 518448);
    _conv2_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _conv2_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 518616);
    _conv2_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 518616);
    _conv2_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _conv2_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 561624);
    _conv2_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 561624);
    _ULite_e1_dw_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_dw_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 561688);
    _ULite_e1_dw_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 561688);
    _ULite_e1_dw_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_dw_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 562136);
    _ULite_e1_dw_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 562136);
    _ULite_e1_dw_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_dw_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 562200);
    _ULite_e1_dw_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 562200);
    _ULite_e1_dw_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_dw_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 562648);
    _ULite_e1_dw_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 562648);
    _ULite_e1_bn_BatchNormalization_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_bn_BatchNormalization_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 562712);
    _ULite_e1_bn_BatchNormalization_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 562712);
    _ULite_e1_bn_BatchNormalization_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_bn_BatchNormalization_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 562776);
    _ULite_e1_bn_BatchNormalization_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 562776);
    _ULite_e1_pw_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_pw_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 562840);
    _ULite_e1_pw_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 562840);
    _ULite_e1_pw_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_pw_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 564888);
    _ULite_e1_pw_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 564888);
    _ULite_e1_act_Constant_output_0_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_act_Constant_output_0_array.data = AI_PTR(g_network_weights_map[0] + 565016);
    _ULite_e1_act_Constant_output_0_array.data_start = AI_PTR(g_network_weights_map[0] + 565016);
    _ULite_e1_act_Add_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_act_Add_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 565020);
    _ULite_e1_act_Add_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 565020);
    _ULite_e1_act_Add_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_act_Add_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 565148);
    _ULite_e1_act_Add_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 565148);
    _ULite_e1_act_Mul_1_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_act_Mul_1_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 565276);
    _ULite_e1_act_Mul_1_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 565276);
    _ULite_e1_act_Mul_1_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e1_act_Mul_1_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 565404);
    _ULite_e1_act_Mul_1_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 565404);
    _ULite_e2_dw_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_dw_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 565532);
    _ULite_e2_dw_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 565532);
    _ULite_e2_dw_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_dw_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 566428);
    _ULite_e2_dw_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 566428);
    _ULite_e2_dw_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_dw_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 566556);
    _ULite_e2_dw_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 566556);
    _ULite_e2_dw_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_dw_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 567452);
    _ULite_e2_dw_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 567452);
    _ULite_e2_bn_BatchNormalization_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_bn_BatchNormalization_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 567580);
    _ULite_e2_bn_BatchNormalization_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 567580);
    _ULite_e2_bn_BatchNormalization_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_bn_BatchNormalization_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 567708);
    _ULite_e2_bn_BatchNormalization_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 567708);
    _ULite_e2_pw_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_pw_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 567836);
    _ULite_e2_pw_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 567836);
    _ULite_e2_pw_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_pw_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 576028);
    _ULite_e2_pw_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 576028);
    _ULite_e2_act_Add_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_act_Add_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 576284);
    _ULite_e2_act_Add_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 576284);
    _ULite_e2_act_Add_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_act_Add_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 576540);
    _ULite_e2_act_Add_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 576540);
    _ULite_e2_act_Mul_1_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_act_Mul_1_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 576796);
    _ULite_e2_act_Mul_1_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 576796);
    _ULite_e2_act_Mul_1_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e2_act_Mul_1_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 577052);
    _ULite_e2_act_Mul_1_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 577052);
    _ULite_e3_dw_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_dw_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 577308);
    _ULite_e3_dw_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 577308);
    _ULite_e3_dw_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_dw_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 579100);
    _ULite_e3_dw_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 579100);
    _ULite_e3_dw_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_dw_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 579356);
    _ULite_e3_dw_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 579356);
    _ULite_e3_dw_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_dw_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 581148);
    _ULite_e3_dw_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 581148);
    _ULite_e3_bn_BatchNormalization_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_bn_BatchNormalization_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 581404);
    _ULite_e3_bn_BatchNormalization_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 581404);
    _ULite_e3_bn_BatchNormalization_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_bn_BatchNormalization_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 581660);
    _ULite_e3_bn_BatchNormalization_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 581660);
    _ULite_e3_pw_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_pw_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 581916);
    _ULite_e3_pw_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 581916);
    _ULite_e3_pw_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_pw_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 614684);
    _ULite_e3_pw_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 614684);
    _ULite_e3_act_Add_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_act_Add_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 615196);
    _ULite_e3_act_Add_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 615196);
    _ULite_e3_act_Add_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_e3_act_Add_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 615708);
    _ULite_e3_act_Add_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 615708);
    _ULite_b5_pw1_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_pw1_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 616220);
    _ULite_b5_pw1_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 616220);
    _ULite_b5_pw1_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_pw1_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 632604);
    _ULite_b5_pw1_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 632604);
    _ULite_b5_dw3_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw3_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 632732);
    _ULite_b5_dw3_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 632732);
    _ULite_b5_dw3_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw3_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 633116);
    _ULite_b5_dw3_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 633116);
    _ULite_b5_dw3_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw3_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 633244);
    _ULite_b5_dw3_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 633244);
    _ULite_b5_dw3_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw3_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 633628);
    _ULite_b5_dw3_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 633628);
    _ULite_b5_dw2_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw2_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 633756);
    _ULite_b5_dw2_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 633756);
    _ULite_b5_dw2_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw2_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 634140);
    _ULite_b5_dw2_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 634140);
    _ULite_b5_dw2_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw2_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 634268);
    _ULite_b5_dw2_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 634268);
    _ULite_b5_dw2_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw2_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 634652);
    _ULite_b5_dw2_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 634652);
    _ULite_b5_dw1_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw1_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 634780);
    _ULite_b5_dw1_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 634780);
    _ULite_b5_dw1_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw1_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 635164);
    _ULite_b5_dw1_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 635164);
    _ULite_b5_dw1_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw1_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 635292);
    _ULite_b5_dw1_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 635292);
    _ULite_b5_dw1_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_dw1_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 635676);
    _ULite_b5_dw1_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 635676);
    _ULite_b5_pw2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_pw2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 635804);
    _ULite_b5_pw2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 635804);
    _ULite_b5_pw2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_pw2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 701340);
    _ULite_b5_pw2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 701340);
    _ULite_b5_act_Mul_1_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_act_Mul_1_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 701852);
    _ULite_b5_act_Mul_1_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 701852);
    _ULite_b5_act_Mul_1_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_b5_act_Mul_1_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 702364);
    _ULite_b5_act_Mul_1_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 702364);
    _ULite_d3_pw_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_pw_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 702876);
    _ULite_d3_pw_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 702876);
    _ULite_d3_pw_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_pw_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 752028);
    _ULite_d3_pw_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 752028);
    _ULite_d3_dw_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_dw_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 752284);
    _ULite_d3_dw_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 752284);
    _ULite_d3_dw_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_dw_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 754076);
    _ULite_d3_dw_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 754076);
    _ULite_d3_dw_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_dw_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 754332);
    _ULite_d3_dw_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 754332);
    _ULite_d3_dw_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_dw_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 756124);
    _ULite_d3_dw_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 756124);
    _ULite_d3_pw2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_pw2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 756380);
    _ULite_d3_pw2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 756380);
    _ULite_d3_pw2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d3_pw2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 772764);
    _ULite_d3_pw2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 772764);
    _ULite_d2_pw_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_pw_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 773020);
    _ULite_d2_pw_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 773020);
    _ULite_d2_pw_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_pw_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 785308);
    _ULite_d2_pw_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 785308);
    _ULite_d2_dw_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_dw_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 785436);
    _ULite_d2_dw_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 785436);
    _ULite_d2_dw_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_dw_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 786332);
    _ULite_d2_dw_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 786332);
    _ULite_d2_dw_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_dw_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 786460);
    _ULite_d2_dw_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 786460);
    _ULite_d2_dw_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_dw_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 787356);
    _ULite_d2_dw_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 787356);
    _ULite_d2_pw2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_pw2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 787484);
    _ULite_d2_pw2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 787484);
    _ULite_d2_pw2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d2_pw2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 791580);
    _ULite_d2_pw2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 791580);
    _ULite_d1_pw_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_pw_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 791708);
    _ULite_d1_pw_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 791708);
    _ULite_d1_pw_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_pw_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 794780);
    _ULite_d1_pw_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 794780);
    _ULite_d1_dw_dw_w_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_dw_dw_w_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 794844);
    _ULite_d1_dw_dw_w_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 794844);
    _ULite_d1_dw_dw_w_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_dw_dw_w_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 795292);
    _ULite_d1_dw_dw_w_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 795292);
    _ULite_d1_dw_dw_h_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_dw_dw_h_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 795356);
    _ULite_d1_dw_dw_h_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 795356);
    _ULite_d1_dw_dw_h_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_dw_dw_h_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 795804);
    _ULite_d1_dw_dw_h_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 795804);
    _ULite_d1_pw2_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_pw2_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 795868);
    _ULite_d1_pw2_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 795868);
    _ULite_d1_pw2_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_pw2_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 796892);
    _ULite_d1_pw2_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 796892);
    _ULite_d1_act_Add_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_act_Add_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 796956);
    _ULite_d1_act_Add_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 796956);
    _ULite_d1_act_Add_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_act_Add_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 797020);
    _ULite_d1_act_Add_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 797020);
    _ULite_d1_act_Mul_1_output_0_scale_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_act_Mul_1_output_0_scale_array.data = AI_PTR(g_network_weights_map[0] + 797084);
    _ULite_d1_act_Mul_1_output_0_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 797084);
    _ULite_d1_act_Mul_1_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _ULite_d1_act_Mul_1_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 797148);
    _ULite_d1_act_Mul_1_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 797148);
    _conv3_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _conv3_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 797212);
    _conv3_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 797212);
    _conv3_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _conv3_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 829980);
    _conv3_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 829980);
    _conv4_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _conv4_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 830108);
    _conv4_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 830108);
    _conv4_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _conv4_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 1171100);
    _conv4_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1171100);
    _value_head_conv_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _value_head_conv_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 1171612);
    _value_head_conv_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1171612);
    _value_head_conv_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _value_head_conv_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 1172124);
    _value_head_conv_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1172124);
    _value_head_fc_fc_0_Gemm_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _value_head_fc_fc_0_Gemm_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 1172128);
    _value_head_fc_fc_0_Gemm_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1172128);
    _value_head_fc_fc_0_Gemm_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _value_head_fc_fc_0_Gemm_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 1213600);
    _value_head_fc_fc_0_Gemm_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1213600);
    _value_head_fc_fc_2_Gemm_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _value_head_fc_fc_2_Gemm_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 1214112);
    _value_head_fc_fc_2_Gemm_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1214112);
    _value_head_fc_fc_2_Gemm_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _value_head_fc_fc_2_Gemm_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 1214624);
    _value_head_fc_fc_2_Gemm_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1214624);
    _policy_head_conv_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _policy_head_conv_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 1214628);
    _policy_head_conv_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1214628);
    _policy_head_conv_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _policy_head_conv_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 1215652);
    _policy_head_conv_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1215652);
    _policy_head_fc_Gemm_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _policy_head_fc_Gemm_output_0_weights_array.data = AI_PTR(g_network_weights_map[0] + 1215660);
    _policy_head_fc_Gemm_output_0_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1215660);
    _policy_head_fc_Gemm_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _policy_head_fc_Gemm_output_0_bias_array.data = AI_PTR(g_network_weights_map[0] + 1268148);
    _policy_head_fc_Gemm_output_0_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1268148);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 19260049,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0xfa430150,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 19260049,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0xfa430150,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_network_data_params_get(&params) != true) {
    err = ai_network_get_error(*network);
    return err;
  }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_network_init(*network, &params) != true) {
    err = ai_network_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

