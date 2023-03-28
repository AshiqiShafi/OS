#include<bits/stdc++.h>
using namespace std;

//First Come First Serve CPU scheduling 

struct Process {
  int id;
  int aTime;
  int bTime;
  int cTime;
  int tatTime;
  int wTime;
  int rTime;
};

bool compATime(Process p1,Process p2){
  return p1.aTime < p2.aTime;
}

bool compId(Process p1,Process p2){
  return p1.id < p2.id;
}

void calculateWtAndTat(Process p[], int n) {
  p[0].cTime = p[0].bTime; //first task will execute first and completed.
  //if our arrival time of process lie in between the previous task's completetion time then we add burst time to that completion time else simply       arrival time of that process+burst time of current process
  for (int i = 1; i < n; i++) {
    if (p[i].aTime < p[i - 1].cTime) { 
      p[i].cTime = p[i - 1].cTime + p[i].bTime;
    }
    else {
      p[i].cTime = p[i].aTime + p[i].bTime;
    }
  }
  for (int i = 0; i < n;i++){
    p[i].tatTime = p[i].cTime - p[i].aTime;
    p[i].wTime = p[i].tatTime - p[i].bTime;
    p[i].rTime = p[i].wTime;
  }
}
void printDetails(Process p[],int n) {
  double averageWaitingTime = 0, averageTurnAroundTime = 0;
  for (int i = 0; i < n; ++i) {
    averageWaitingTime += p[i].wTime;
    averageTurnAroundTime += p[i].tatTime;
  }
  averageWaitingTime /= n;
  averageTurnAroundTime /= n;
  for (int i = 0; i < n; ++i) {
    cout << "Process " << p[i].id << " waiting time = " << p[i].wTime << endl;
    cout << "Process " << p[i].id << " turn around time = " << p[i].tatTime << endl;
    cout << "\t\n";
  }
  cout << "Average waiting time =  " << averageWaitingTime << endl;
  cout << "Average turn around time " << averageTurnAroundTime << endl;
}

int main() {
  int n;
  cout << "Enter number processes: ";
  cin >> n;
  cout << "Enter Arrival time and Burst Time of process: \n";
  Process p[n];
  for (int i = 0; i < n;i++) {
    p[i].id = i + 1;
    cin >> p[i].aTime >> p[i].bTime;
  }
  sort(p, p + n,compATime); //Sort all the processes according to burst time
  calculateWtAndTat(p, n);
  sort(p, p + n, compId);
  printDetails(p, n);
  return 0;
}
