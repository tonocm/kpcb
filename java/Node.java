class Node{
  
  public int data;
  public Node next, prev;
  
  public Node(int data, Node next, Node prev){
    this.data = data;
    this.next = next;
    this.prev = prev;
  }
  public Node(){
    this.data = 0;
    this.next = null;
    this.prev = null;
  }
}