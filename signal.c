#include <fcntl.h>

#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>





#define LED0_PATH "/sys/class/gpio/export"
#define SYSFS_ADC_DIR "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
#define MAX_BUF 64


int main(void){

        int gpio_set = open("/sys/class/gpio/export", O_WRONLY | O_TRUNC);
        write(gpio_set, "68", sizeof("68"));
        write(gpio_set, "67", sizeof("67"));
        write(gpio_set, "66", sizeof("66"));
        close(gpio_set);


        // Red Light

        int di_red = open("/sys/class/gpio/gpio68/direction", O_WRONLY | O_TRUNC);
        write(di_red, "out", sizeof("out"));
        close(di_red);

        int val_red = open("/sys/class/gpio/gpio68/value", O_WRONLY | O_TRUNC);
        write(val_red, "1", sizeof("1"));
        write(val_red, "0", sizeof("0"));



        int al_red = open("/sys/class/gpio/gpio68/active_low", O_WRONLY | O_TRUNC);
        write(al_red, "0", sizeof(0));
        close(al_red);


        // Yellow Light

        int di_yel = open("/sys/class/gpio/gpio67/direction", O_WRONLY | O_TRUNC);
        write(di_yel, "out", sizeof("out"));
        close(di_yel);

        int val_yel = open("/sys/class/gpio/gpio67/value", O_WRONLY | O_TRUNC);
        write(val_yel, "1", sizeof("1"));
        write(val_yel, "0", sizeof("0"));



        int al_yel = open("/sys/class/gpio/gpio67/active_low", O_WRONLY | O_TRUNC);
        write(al_yel, "0", sizeof(0));
        close(al_yel);


        // Green Light

        int di_grn = open("/sys/class/gpio/gpio66/direction", O_WRONLY | O_TRUNC);
        write(di_grn, "out", sizeof("out"));
        close(di_grn);

        int val_grn = open("/sys/class/gpio/gpio66/value", O_WRONLY | O_TRUNC);
        write(val_grn, "1", sizeof("1"));
        write(val_grn, "0", sizeof("0"));


        int al_grn = open("/sys/class/gpio/gpio66/active_low", O_WRONLY | O_TRUNC);
        write(al_grn, "0", sizeof(0));
        close(al_grn);





        //Light




        double fd = 0.0;
        char buf[MAX_BUF] = {0};
        char ch[5] = {0,0,0,0,0};
        int ch_i=0;

        while(1){

                write(val_red, "1", sizeof("1"));

                sleep(5);

                snprintf(buf,sizeof(buf),SYSFS_ADC_DIR);
                fd= open(buf,O_RDONLY);
                read(fd,ch,4);

                ch_i = atoi(ch);
                printf("%d\n",ch_i);



                if(ch_i < 200){
                        //printf("it's night\n");
                        while(1){

                                write(val_red, "0", sizeof("0"));
                                write(val_yel, "0", sizeof("0"));
                                write(val_grn, "0", sizeof("0"));

                                usleep(1000000);

                                write(val_yel, "1", sizeof("1"));
                                usleep(1000000);


                                fd= open(buf,O_RDONLY);
                                read(fd,ch,4);
                                ch_i = atoi(ch);
                                printf("%d\n",ch_i);
                                close(fd);

                                if(ch_i >= 200){
                                                write(val_yel, "0",sizeof("0"));
                                                break;
                                        }
                                }
                }



                close(fd);

                write(val_red, "0", sizeof("0"));
                write(val_grn, "1", sizeof("1"));

                sleep(5);

                snprintf(buf,sizeof(buf),SYSFS_ADC_DIR);
                fd= open(buf,O_RDONLY);
                read(fd,ch,4);

                ch_i = atoi(ch);
                printf("%d\n",ch_i);



                if(ch_i < 200){
                        //printf("it's night\n");
                        while(1){

                                write(val_red, "0", sizeof("0"));
                                write(val_yel, "0", sizeof("0"));
                                write(val_grn, "0", sizeof("0"));

                                usleep(1000000);

                                write(val_yel, "1", sizeof("1"));
                                usleep(1000000);


                                fd= open(buf,O_RDONLY);
                                read(fd,ch,4);
                                ch_i = atoi(ch);
                                printf("%d\n",ch_i);
                                close(fd);

                                if(ch_i >= 200){
                                                write(val_yel, "0",sizeof("0"));
                                                break;
                                        }
                                }
                }



                close(fd);



                write(val_grn, "0", sizeof("0"));
                write(val_yel, "1", sizeof("1"));

                sleep(3);

                snprintf(buf,sizeof(buf),SYSFS_ADC_DIR);
                fd= open(buf,O_RDONLY);
                read(fd,ch,4);

                ch_i = atoi(ch);
                printf("%d\n",ch_i);



                if(ch_i < 200){
                        //printf("it's night\n");
                        while(1){

                                write(val_red, "0", sizeof("0"));
                                write(val_yel, "0", sizeof("0"));
                                write(val_grn, "0", sizeof("0"));

                                usleep(1000000);

                                write(val_yel, "1", sizeof("1"));
                                usleep(1000000);


                                fd= open(buf,O_RDONLY);
                                read(fd,ch,4);
                                ch_i = atoi(ch);
                                printf("%d\n",ch_i);
                                close(fd);

                                if(ch_i >= 200){
                                                write(val_yel, "0",sizeof("0"));
                                                break;
                                        }
                                }
                }



                close(fd);




                write(val_yel, "0", sizeof("1"));



        }

        return 0;

}
