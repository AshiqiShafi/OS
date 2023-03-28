#include<bits/stdc++.h>
using namespace std;
 
int main() {
  cout << "Enter the number of process: ";
  int n; cin >> n;
  vector<int> arrivalTime(n + 1), burstTime(n + 1);
  cout << "Enter arrival time and burst time:" << endl;
  int totBurst = 0;
  for (int i = 0; i < n; i++) {
    cin >> arrivalTime[i] >> burstTime[i];
    totBurst += burstTime[i];
  }
  vector<int> waitingTime(n, 0), turnAroundTime(n, 0);
  burstTime[n] = 9999;
  for (int time = 0; time < totBurst;) {
    int mini = n;
    for (int i = 0; i < n; i++) {
      if (arrivalTime[i] <= time && burstTime[i] > 0 && burstTime[i] < burstTime[mini]) {
        mini = i;
      }
    }
    turnAroundTime[mini] = time + burstTime[mini] - arrivalTime[mini];
    waitingTime[mini] = time - arrivalTime[mini];
    time += burstTime[mini];
    burstTime[mini] = 0;
  }
  double averageWaitingTime = 0, averageTurnAroundTime = 0;
  for (int i = 0; i < n; ++i) {
    averageWaitingTime += waitingTime[i];
    averageTurnAroundTime += turnAroundTime[i];
  }
  averageWaitingTime /= n;
  averageTurnAroundTime /= n;
  for (int i = 0; i < n; ++i) {
    cout << "Process " << i << " waiting time = " << waitingTime[i] << endl;
    cout << "Process " << i << " turn around time = " << turnAroundTime[i] << endl;
    cout << "\t\n";
  }
  cout << "Average waiting time =  " << averageWaitingTime << endl;
  cout << "Average turn around time = " << averageTurnAroundTime << endl;
  return 0;
}
