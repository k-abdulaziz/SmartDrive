import sys
import time
import serial
from threading import *
from PyQt5.QtWidgets import QMainWindow, QWidget, QApplication, QLCDNumber, QPushButton, QLabel
import RPi.GPIO as GPIO

from mainwindow import Ui_MainWindow as mainwindow

# The serial port that the cruise control system is connected to.
ser = serial.Serial('/dev/ttyAMA0', 9600)


class MainWindow(QMainWindow, mainwindow):
    """The main window of the cruise control system."""

    def __init__(self, parent=None):
        """Initialize the main window."""
        super().__init__(parent)

        # Set up the user interface.
        self.setupUi(self)

        # Connect the buttons to their respective functions.
        self.ACC_PB.clicked.connect(self.ACC_Mode)
        self.LDW_PB.clicked.connect(self.LDW_Mode)
        self.LKS_PB.clicked.connect(self.LKS_Mode)
        self.AEB_PB.clicked.connect(self.AEB_Mode)
        self.DefaultSpeed_BP.clicked.connect(self.EnableDefaultSpeed)
        self.Speed_PB.clicked.connect(self.SetSpeedACC)

        # Set up the gauges.
        self.widget.enableBarGraph = True
        self.widget.setEnableBarGraph(False)
        self.widget.units = "m/min"
        self.widget.minValue = 0
        self.widget.maxValue = 100
        self.widget.scalacount = 5

        # Connect the gauges to their respective functions.
        self.widget.valueChanged.connect(self.update_LCD)
        self.SetSpeed_SB.valueChanged.connect(self.update_SetSpeedLCD2)

        # Set the gauge theme.
        self.widget.setGaugeTheme(11)

        # Set the colors of the gauge.
        self.widget.setScalePolygonColor("Red", "blue", "green")
        self.widget.setNeedleCenterColor("white", "#2D16B3", "#green")
        self.widget.setBigScaleColor("white")
        self.widget.setFineScaleColor("cyan")
        self.widget.setScaleValueColor(255, 255, 255, 255)
        self.widget.setDisplayValueColor(255, 255, 255, 255)
        self.widget.setNeedleColor(255, 255, 255, 255)
        self.widget.setEnableCenterPoint(True)
        self.widget.setMouseTracking(False)

        # Start the thread that reads data from the serial port.
        self.threadRead()

        # Show the main window.
        self.show()

    def ACC_Mode(self):
        """Set the cruise control system to ACC mode."""
        self.Mode_View.setText('ACC')
        self.mode = 1
        ser.write(b"C")
        print('sent C')

    def EnableDefaultSpeed(self):
        """Enable the default speed for ACC and NCC modes."""
        ser.write(b"F")
        print('sent F')

    def SetSpeedACC(self):
        """Set the desired speed for ACC mode."""
        value = self.SetSpeed_SB.value()  # Get the current value of the spin box
        ser.write(b"S")
        print('sent S')
        # Convert the value to bytes and send it via the serial connection
        ser.write(str(value).encode())
        print('Sent value:', value)

    def AEB_Mode(self):
        """Set the cruise control system to AEB mode."""
        self.Mode_View.setText('AEB')
        self.mode = 2
        ser.write(b"E")
        print('sent E')

    def LDW_Mode(self):
        """Set the cruise control system to LDW mode."""
        self.Mode_View.setText('LDW')
        self.mode = 3
        ser.write(b"D")
        print('sent D')

		def LKS_Mode(self):
		    """Set the cruise control system to LKS mode."""
		    # Set the text of the mode label to "LKS".
		    self.Mode_View.setText('LKS')

		    # Set the mode variable to 4.
		    self.mode = 4

		    # Send the "K" command to the serial port.
		    ser.write(b"K")

		    # Print a message to the console indicating that the command was sent.
		    print('sent K')


		def Get_SetSpeed_Value(self):
		    """Get the current value of the speed spin box."""
		    # Get the value of the spin box.
		    value = self.speedSpinBox.value()

		    # Return the value.
		    return value


		def SerUpdate(self):
		    """Read data from the serial port and update the gauges."""
		    # Read a byte from the serial port.
		    c = ser.read(1)

		    # If the byte is a newline character, then read the next 50 bytes.
		    if c == b'\r':
		        char = ser.read(50)

		        # Split the bytes into a list.
		        msg = char.split(b' ')

		        # Get the speed value from the message.
		        speed = msg[0].strip(b'\x00\r')

		        # Print the speed value to the console.
		        print("speed = {}".format(speed))

		        # Convert the speed value to an integer.
		        Speed = int(speed)

		        # Update the value of the gauge.
		        self.widget.updateValue(Speed)

		        # Create a list of 50 speed values.
		        speed_array = []
		        for i in range(50):
		            speed_array.append(Speed)

		        # Update the speed array of the gauge.
		        self.widget.updateSpeedArray(speed_array)
				self.widget.updateSpeedArray(speed_array)


if __name__ == '__main__':

    app = QApplication(sys.argv)

    window = MainWindow()

    window.show()

    window.threadRead()

    sys.exit(app.exec_())