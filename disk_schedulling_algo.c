#include<stdio.h>
void main()
{
	//char ch ='t';
	//while(ch=='t' || ch=='T')
	//{
	int oy;
	printf("----->CIRCULAR SCAN DISK SCHEDULLING ALGORITHM<-----\n");
	printf("\n---------------------------------------\n");
	printf("press 1 to get answer form user input for c-scan disk schedulling algo.\n");
    printf("press 2 to get answer of given question:\n");
    printf("\n----------------------------------------\n");
    scanf("%d",&oy);
    switch(oy)
    	{
        case 1:
            {
            	int queue[20],n,head,i,j,k,distance=0,h,range,difference,temp,enter_element,queue1[20],queue2[20],t1=0,t2=0;
            	float avg;
            	printf("Enter range of disk cylinder\n");
            	scanf("%d",&range);
            	printf("Enter head position where the queue is serving request\n");
            	scanf("%d",&head);
            	printf("Enter the size of queue request\n");
            	scanf("%d",&n);
            	printf("-------------------------------------------------------\n");
            	printf("Enter the queue of disk positions to be read\n");
            	for(i=1;i<=n;i++)
           			{
           				scanf("%d",&enter_element);

                        if(enter_element>=head)
                        {
                        	queue1[t1]=enter_element;
                            t1++;
                        }
                        else
                        {
                                    queue2[t2]=enter_element;
                                    t2++;
                        }
        			}
        			printf("-------------------------------------------------------\n");
            	for(i=0;i<t1-1;i++)
            		{
                        for(j=i+1;j<t1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                        temp=queue1[i];
                                        queue1[i]=queue1[j];
                                        queue1[j]=temp;
                                    }
                        }
            		}
            	for(i=0;i<t2-1;i++)
            		{
                        for(j=i+1;j<t2;j++)
                        {
                            if(queue2[i]>queue2[j])
                                    {
                                        temp=queue2[i];
                                        queue2[i]=queue2[j];
                                        queue2[j]=temp;
                                    }
                        }
            		}
            	for(i=1,j=0;j<t1;i++,j++)
            		{
            			queue[i]=queue1[j];
            		}
				queue[i]=range;
            	queue[i+1]=0;
            	for(i=t1+3,j=0;j<t2;i++,j++)
            		{
            			queue[i]=queue2[j];
            		}
            	queue[0]=head;
            	printf("\n______________________________________________________\n");
            	printf("\nFor getting request we need to move as follows:\n");
            	for(h=0;h<n;h++)
            		{
            			printf("(%d ->> %d)\n",queue[h],queue[h+1]);
					}
				printf("\n______________________________________________________\n");
            	for(j=0;j<=n+1;j++)
            		{
                        difference=abs(queue[j+1]-queue[j]);
                        distance+=difference;
                    printf("\n Moves from %d -->> %d with the difference of %d\n",queue[j],queue[j+1],difference);
            	}
            	printf("Total distance (in cylinders) that the disk arm moves to satisfy all the pending requests is:%d\n",distance);
            	//printf("\npress t to check result for another value:");
				//scanf("%c\n",&ch);
				//system("cls");
				break;
        	}
        	case 2:
        		{
        	 		int queue[20],n,head,i,j,k,distance=0,range,difference,temp,queue1[20],queue2[20],temp1=0,temp2=0;
            		float avg;
            		range = 5000;
            		head  = 143;
            		n = 9;
            		int h;
            		printf("Range of disk cylinder:%d",range);
            		printf("\nHead position where the queue is serving request:%d",head);
            		printf("\nThe pandding request values in given fifo order:86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130\n");
            		int ar[10]= {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
            	for(i=0;i<n;i++)
            	{
                    if(ar[i]>=head)
                        {
                            queue1[temp1]=ar[i];
                            temp1++;
                        }
                        else
                        {
                            queue2[temp2]=ar[i];
                            temp2++;
                        }
            	}
            	for(i=0;i<temp1-1;i++)
            	{
                    for(j=i+1;j<temp1;j++)
                        {
                            if(queue1[i]>queue1[j])
                            {
                                temp=queue1[i];
                                queue1[i]=queue1[j];
                                queue1[j]=temp;
                            }
                        }
            	}
            	for(i=0;i<temp2-1;i++)
            	{
                	for(j=i+1;j<temp2;j++)
                    {
                        if(queue2[i]>queue2[j])
                        {
                            temp=queue2[i];
                            queue2[i]=queue2[j];
                            queue2[j]=temp;
                        }
                    }
            	}
            	for(i=1,j=0;j<temp1;i++,j++)
            	{
            		queue[i]=queue1[j];
            	}
            	queue[i]=range;
            	queue[i+1]=0;
            	
            	for(i=temp1+3,j=0;j<temp2;i++,j++)
            	{
					queue[i]=queue2[j];
				}
				queue[0]=head;
            	
            	printf("\n______________________________________________________\n");
            	printf("\nFor getting request we need to move as follows:\n");
            	for(h=0;h<n;h++)
            	{
            		printf("(%d ->> %d)\n",queue[h],queue[h+1]);
				}
				printf("\n______________________________________________________\n");
            	for(j=0;j<=n+1;j++)
            	{
                    difference=abs(queue[j+1]-queue[j]);
                    distance+=difference;
                    printf("\n %d -->> %d with the difference of %d\n",queue[j],queue[j+1],difference);
            	}
            	printf("Total distance (in cylinders) that the disk arm moves to satisfy all the pending requests is:%d\n",distance);
            	//printf("\npress t to check result for another value:");
				//scanf("%c\n",&ch);
				//system("cls");
            	break;
				}
			default:
				{
					printf("Invaild request press t to re-enter else press any key to exit.\n");
					
					break;
				}
		}
	
}
