import os
import shutil
import time

for i in range(1,21):
	os.system("gen.exe")
	os.system("H.exe")
	shutil.copy("./input.txt","./Testcase/input"+str(i)+".txt")
	shutil.copy("./output.txt","./Testcase/output"+str(i)+".txt")
	time.sleep(1)

