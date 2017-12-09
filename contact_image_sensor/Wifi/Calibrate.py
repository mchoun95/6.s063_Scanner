# Sensor Calibration Code

import numpy as np
import scipy
from serial import *
from io import RawIOBase

from serial import tools
from serial.tools import list_ports
from serial.tools.list_ports_common import ListPortInfo
from serial import serialwin32 as serial

ser = tools.list_ports.comports();

# serbase = serial.serialutil.SerialBase('COM8')
ser = serial.Serial('COM8')
# ser.open()

prev_line = '0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0'
cal = prev_line

def read_line():
	line = ''
	while(ser.in_waiting > 0):
		resp = ser.read()
		line += resp.decode()
	return line

def process_calibration(line, cal_line):
	line_list = line.split(",")[0:-1]
	line_list = np.array([float(i) for i in line_list])

	cal_line_list = cal_line.split(",")
	cal_line_list = np.array([float(i) for i in cal_line_list])
	
	for i in range(len(line_list)):
		if line_list[i] > cal_line_list[i]:
			cal_line_list[i] = line_list[i]

	cal_line_list = np.array([str(i) for i in cal_line_list])
	comma = ','
	cal = comma.join(cal_line_list)
	return cal

f = open("./calibrate.txt", "w+")
f.close()


while(1):
	if (ser.in_waiting > 0):
		line = read_line()
		cal = process_calibration(line, cal)

		print(cal)
		#f.open("image.txt", "a")


		# f = open("./calibrate.txt", "w+")
		# f.write(cal)
		# f.close()
		#print(line)

