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

def read_line():
	line = ''
	while(ser.in_waiting > 0):
		resp = ser.read()
		line += resp.decode()
	return line

def process_line(line):
	line_list = line.split(",")[0:-1]
	line_list = np.array([float(i) for i in line_list])
	lin_list = avg_filt(line_list)
	thresh = np.mean(line_list);
	if thresh < 50:
		line_list = [0 for i in range(40)]

	else:
		line_list = line_list>thresh
		line_list = line_list.astype(np.int)
	
	line_list = np.array([str(i) for i in line_list])
	comma = ''
	p_line = comma.join(line_list)
	p_line += '\n\r'
	return p_line

def avg_filt(x):
	avg = x[0:len(x)-2] + x[1:len(x)-1] + x[2:len(x)]
	avg_com = [x[0]] + avg.tolist() + [x[-1]]
	return avg_com

f = open("./image.txt", "w+")
f.close()

while(1):
	if (ser.in_waiting > 0):
		line = read_line()
		p_line = process_line(line)
		print(p_line)
		#f.open("image.txt", "a")
		f = open("./image.txt", "a+")
		f.write(p_line)
		f.close()

