import os
filelistCommand = "ls input_random_*.txt > filelist.txt"    #store list of all input files into filelist.txt
os.system(filelistCommand)                                  #run the above command.
filelist = open("filelist.txt", 'r')                        #take the filelist into a variable
for fil in filelist:                                        #for each file in the list.
    bashCommand = "./Bellman_Ford_APSP < "+fil[:-1]+" > o.txt"
    #the last character of "fil" (filename) is '\n'. store output in o1.txt
    #print bashCommand
    os.system(bashCommand)
    print fil[:-1]
    bash2 = "diff o.txt out"+fil[2:-1]
    #print bash2
    #fil is "input_random_*_*.txt\n" so we will remove first 2 chars.
    os.system(bash2)
