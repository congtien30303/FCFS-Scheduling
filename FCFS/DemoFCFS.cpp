//#include <stdio.h>
//
//// pid: Process ID
//// ar: arrivalTime  Thời gian vào hàng chờ
//// bt: burstTime    Thời gian thực thi
//// n: number of elements
//
//void Input(int &n,int ar[],int bt[], int pid[])
//{
//    printf("Enter number of processes: ");
//    scanf_s("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        printf("Enter arrival time for process %d: ", (i + 1));
//        scanf_s("%d", &ar[i]);
//        printf("Enter burst time for process %d: ", (i + 1));
//        scanf_s("%d", &bt[i]);
//        pid[i] = i + 1;
//    }
//}
//
//int Check(int n, int ar[], int Comp[])
//{
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (Comp[i] < ar[i+1])
//        {
//            return 1; // ko thõa
//        }
//    }
//
//    return 0; // thõa
//}
//
//void swap(int &a,int &b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//void SortByarrivalTime(int n, int ar[], int bt[], int pid[])
//{
//    for (int i = 0; i < n -1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (ar[i] > ar[j]) 
//            {
//                swap(ar[i], ar[j] );
//                swap(bt[i], bt[j]);
//                swap(pid[i], pid[j]);
//            }
//        }
//    }
//}
//
//// Comp: Complete Thời gian hoàn thành
//// ta: Turnaround  Tổng thời gian thực hiện tiến trình
//// wt: Waiting Thời gian đợi
//
//void Calculate(int n,int ar[],int bt[],int  Comp[],int ta[],int wt[],float &avgwt, float &avgta)
//{
//    for (int i = 0; i < n; i++) 
//    {
//        if (i == 0)// sau khi sắp xếp P thứ nhất là P thực hiện đầu tiên
//        {       
//            Comp[i] = ar[i] + bt[i];
//        }
//        else 
//        {
//            if (ar[i] > Comp[i - 1]) // nếu tgian đến của P hiện tại lớn hơn tgian hoàn tất của P trước
//            {
//                Comp[i] = ar[i] + bt[i];
//            }
//            else 
//            {
//                Comp[i] = Comp[i - 1] + bt[i];
//            }
//        }
//        ta[i] = Comp[i] - ar[i]; // Tổng tgian thực hiện = tgian hoàn tất - tgian vào 
//        wt[i] = ta[i] - bt[i];// Tgian chờ = Tổng tgian - tgian hoàn tất
//        avgwt += wt[i]; // tính tổng thời gian chờ
//        avgta += ta[i]; // tính tổng (tổng tgian hoàn tất)
//    }
//    avgwt = (avgwt / n); // tính trung bình tgian chờ
//    avgta = (avgta / n); // tính trung bình  tổng tgian hoàn tất
//}
//
//
//void DrawChart(int n, int ar[], int bt[], int pid[], int Comp[], int ta[], int wt[])
//{   
//    printf("\n\n\t\t\t\tGantt Chart\n\n");
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += bt[i];
//    }
//    sum = sum + n + 1;
//
//    for (int i = 0; i < sum; i++) // vẽ hàng đầu
//    {
//        printf("* ");
//    }
//
//    printf("\n*"); // vẽ hàng thứ 2
//    int j = 0;
//    int count = 0;
//    for (int i = 0; i < ((sum*2)-1); i++)
//    {
//        if (count == ((bt[j]*2)+1))
//        {
//            printf("*");
//            j++;
//            count = 0;
//        }
//        else
//        {
//            printf(" ");
//            count++;
//        }
//    }
//
//    printf("\n*"); // Vẽ hàng thứ 3
//    j = 0;
//    int x = 0;
//    count = 0;
//    for (int i = 0; i < ((sum * 2) - 1); i++)
//    {
//        if (count == ((bt[j] * 2) + 1))
//        {
//            printf("*");
//            j++;
//            count = 0;
//        }
//        else if (count == (((bt[j] * 2) + 1)/2))
//        {
//            printf("P%d", pid[x]);
//            x++;
//            count +=2;
//        }
//        else
//        {
//            printf(" ");
//            count++;
//        }
//    }
//
//
//    printf("\n*");    // Vẽ hàng thứ 4
//    j = 0;
//    count = 0;
//    for (int i = 0; i < ((sum * 2) - 1); i++)
//    {
//        if (count == ((bt[j] * 2) + 1))
//        {
//            printf("*");
//            j++;
//            count = 0;
//        }
//        else
//        {
//            printf(" ");
//            count++;
//        }
//    }
//    printf("\n");
//
//    for (int i = 0; i < sum; i++) // vẽ hàng thứ 5
//    {
//        printf("* ");
//    }
//
//
//    printf("\n%d",ar[0]); // vẽ hàng cuối
//    j = 0;
//    count = 0;
//    for (int i = 0; i < ((sum * 2) - 1); i++)
//    {
//        if (count == ((bt[j] * 2) + 1))
//        {
//            if (Comp[j] > 9)
//            {
//                printf("%d", Comp[j]);
//                j++;
//                count = 1;
//            }
//            else
//            {
//                printf("%d", Comp[j]);
//                j++;
//                count = 0;
//            }
//        }
//        else
//        {
//            printf(" ");
//            count++;
//        }
//    }
//    printf("\n\n");
//}
//
//
//int main() {
//    int n;
//    float avgwt = 0, avgta = 0;  
//    int pid[100], ar[100], bt[100], Comp[100], ta[100], wt[100];
//
//    Input(n, ar, bt, pid);
//    SortByarrivalTime(n, ar, bt, pid);
//    Calculate(n, ar, bt, Comp, ta, wt, avgwt, avgta);
//
//
//    DrawChart(n, ar, bt, pid, Comp, ta, wt);
//
//    printf("\nPID\tArrival\tBurst\tComplete\tTurnaround\tWaiting\n");
//    for (int i = 0; i < n; i++) {
//        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", pid[i], ar[i], bt[i], Comp[i], ta[i], wt[i]);
//    }
//
//    printf("\nAverage waiting time: %.2f", avgwt);
//    printf("\nAverage turnaround time: %.2f", avgta);
//
//    return 0;
//}