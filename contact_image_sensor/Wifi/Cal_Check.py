# Calibration_Check
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

cal_check = [62.0,59.67,57.5,59.33,54.67,56.67,54.33,61.0,64.67,60.33,56.67,53.0,55.67,51.0,62.0,56.33,60.33,61.67,66.0,56.67,55.0,55.33,62.67,60.33,61.67,61.0,57.67,62.67,55.67,60.0,64.0,63.33,59.33,63.0,62.67,61.0,56.0,54.5,59.67,70.0]


def read_line():
	line = ''
	while(ser.in_waiting > 0):
		resp = ser.read()
		line += resp.decode()
	return line

def check_calibration(line, cal):
	line_list = line.split(",")[0:-1]
	line_list = np.array([float(i) for i in line_list])

	for i in range(len(line_list)):
		line_list[i] = line_list[i] - cal[i]
		if line_list[i] < 0:
			line_list[i] = 0

	line_list = np.array([str(i) for i in line_list])
	comma = ','
	p_line = comma.join(line_list)
	return p_line

# f = open("./calibrate.txt", "w+")
# f.close()


while(1):
	if (ser.in_waiting > 0):
		line = read_line()
		check = check_calibration(line, cal_check)

		print(check)
		#f.open("image.txt", "a")


		# f = open("./calibrate.txt", "w+")
		# f.write(cal)
		# f.close()
		#print(line)

