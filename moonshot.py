import serial

try:
	arduino = serial.Serial("/dev/cu.usbmodem43", timeout=1)
except:
	print("Error on port!")

rawdata = []
count = 0

while count <= 600:
	rawdata.append(str(arduino.readline()))
	count = count + 1

file = open("moonshot/test.txt", mode = 'w')
for i in range(len(rawdata)):
	file.write(rawdata[i])
file.close()

# from git import Repo

# repo_dir = 'moonshot'
# repo = Repo(repo_dir)
# file_list = [
#     'test.txt'
# ]
# commit_message = 'Add file'
# repo.index.add(file_list)
# repo.index.commit(commit_message)
# origin = repo.remote('origin')
# origin.push()