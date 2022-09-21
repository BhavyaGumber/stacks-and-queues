void rev(queue<int> &q){
  if(q.empty())return;
  int data = q.front();
  q.pop();
  rev(q);
  q.push(data);
}
