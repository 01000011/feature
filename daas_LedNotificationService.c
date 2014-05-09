#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "daas_LedNotificationService.h"
#define MAX_BUF 64
JNIEXPORT void JNICALL Java_daas_LedNotificationService_send(JNIEnv * env, jobject obj)
{
//	FILE *fp;
	char path[MAX_BUF];
	snprintf(path,sizeof path, "/dev/notify_man");
//	if((fp = fopen(path,"w")) == NULL){
		printf("file open failed");
//		return 1;
//	        }
       //rewind(fp);
       //fprintf(fp, "bmp085 0x77\n");
       //fflush(fp);
 //      fclose(fp);
       /*while(1){
              sleep(2);
              char buf[MAX_BUF];
              //Attempt to open the file of the device.
              snprintf(path, sizeof path, "/sys/bus/i2c/drivers/bmp085/3-0077/temp0_input");
              if((fp = fopen(path, "r")) == NULL){
	            printf("cannot open device file");
	            return 1;
	            }
              //Attempt to read the temperature from the device.
              if((fgets(buf, MAX_BUF, fp)) == NULL){
	            printf("cannot read device");
	           }
              fclose(fp);
              float temp = atoi(buf);
              float tempd = temp / 10;
              printf("Current Temperature: %f\n",tempd);
             //Attempt to open the file of the device.
             snprintf(path, sizeof path, "/sys/bus/i2c/drivers/bmp085/3-0077/pressure0_input");
             if((fp = fopen(path, "r")) == NULL){
	          printf("cannot read");
	          return 1;
	          }
             //Attempt to read the pressure from the device.
             if((fgets(buf, MAX_BUF, fp)) == NULL){
	          printf("cannot read");
	          }
             fclose(fp);
             float pressure = atoi(buf);
             float pressured = pressure / 100;
             printf("Current Pressure: %f\n\n",pressured);
	}*/
}

JNIEXPORT void JNICALL Java_daas_LedNotificationService_init(JNIEnv *env, jobject obj)
{

}

JNIEXPORT jint JNICALL Java_daas_LedNotificationService_ismessageable(JNIEnv * env, jobject obj)
{
	return 0;
}

JNIEXPORT void JNICALL Java_daas_LedNotificationService_message(JNIEnv *env, jobject obj, jstring str)
{

}
