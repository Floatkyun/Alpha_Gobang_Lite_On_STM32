# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 12:37:51 2024

@author: hp
"""

from torchsummary import summary
from onnxsim import simplify
import torch
import onnx

onnx_temp="best_policy_value_net.onnx"
model="D:/H743/Alpha-GoLite/Alpha-GoLite/Alpha-GoLite/best_policy_value_net5600.pth"
net = torch.load(model,map_location=torch.device('cpu'))
net.eval()
summary(net, input_size=(6, 9, 9))
torch_input=torch.zeros(1,6,9,9)
input_name=["input"]
output_name=["output"]
torch.onnx.export(net,torch_input,onnx_temp,input_names=input_name,output_names=output_name,opset_version=17)



model = onnx.load(onnx_temp)  # load onnx model
model_simp, check = simplify(model)
assert check, "Simplified ONNX model could not be validated"
onnx.save(model_simp, "best_policy_value_net_simplify.onnx")