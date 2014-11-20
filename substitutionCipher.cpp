/**
* Input directions:
* 0 to exit program
* 1 to reset cipher
* 2 to undo last change
* 3 to print current working text to a file
* 
* can only undo once
**/


#include<iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
using namespace std;


int main()
{
	char table[26][2];
	
	int count = 0;
	for(int i=65; i<90; i++)
	{
		table[count][0] = i;
		count++;
	}
	for(int i=0; i<count; i++)
	{
		cout<<table[i][0];
	}
	char cipher[] = "LIVITCSWPIYVEWHEVSRIQMXLEYVEOIEWHRXEXIPFEMVEWHKVSTYLXZIXLIKIIXPIJVSZEYPERRGERIM\nWQLMGLMXQERIWGPSRIHMXQEREKIETXMJTPRGEVEKEITREWHEXXLEXXMZITWAWSQWXSWEXTVEPMRXRSJ\nGSTVRIEYVIEXCVMUIMWERGMIWXMJMGCSMWXSJOMIQXLIVIQIVIXQSVSTWHKPEGARCSXRWIEVSWIIBXV\nIZMXFSJXLIKEGAEWHEPSWYSWIWIEVXLISXLIVXLIRGEPIRQIVIIBGIIHMWYPFLEVHEWHYPSRRFQMXLE\nPPXLIECCIEVEWGISJKTVWMRLIHYSPHXLIQIMYLXSJXLIMWRIGXQEROIVFVIZEVAEKPIEWHXEAMWYEPP\nXLMWYRMWXSGSWRMHIVEXMSWMGSTPHLEVHPFKPEZINTCMXIVJSVLMRSCMWMSWVIRCIGXMWYMX";
	char manip[1000];
	char undo[1000];
	strncpy(manip, cipher, sizeof(cipher));
	strncpy(undo, cipher, sizeof(cipher));
	
	char current;
	char change;
	while(1)
	{
		//get current command
		cout<<endl<<"---------------------------------------"<<endl<<endl<<manip;
		cout<<endl<<endl<<"What letter to change?"<<endl;
		cin>>current;
		
		//exit on 0
		if(current =='0')
			break;
		
		//reset on one
		if(current == '1')
			strncpy(manip, cipher, sizeof(cipher));
			else if (current == '2')
				strncpy(manip, undo, sizeof(cipher));
			else if (current == '3')
				{
					ofstream myfile;
					myfile.open ("CIPHERPRINT.txt");
					myfile << manip;
					myfile.close();
					exit(0);
				}
		else { 
			strncpy(undo, manip, sizeof(cipher));
			cout<<"Change to what?"<<endl;
			cin>>change;
		
			change = tolower(change);
			
			
			//change letters
			for(int i=0; i<sizeof(manip); i++)
			{
				if(manip[i] == current)
				{
					manip[i] = change;
				}
			}
		}
		
	}	

	return 0;
}


