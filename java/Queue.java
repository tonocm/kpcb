class Queue{
  
  public int emptySpace; 
  public Node headNode;
  
  
  public Queue(int emptySpace){
    
    this.emptySpace = emptySpace;
    headNode = new Node();
    
  }
  
  public void enqueue(int value){
    if(headNode == null){
      headNode.data = value;
      //headNode.next = headNode; //not actually necessary
      headNode.prev = headNode;
    }
    else{
      Node current = new Node();
      current.data = value;
      current.next = headNode;
      current.prev = headNode.prev;
      headNode.prev = current;
      headNode = current;
    }
      emptySpace--;
  }
  public int dequeue(){
    
    int out;
    out = headNode.prev.data;
    headNode.prev.prev.next = headNode;
    headNode.prev = headNode.prev.prev;
    
    emptySpace++;
    
    return out;
  }
  public void print(){
    
  }
}