// See https://aka.ms/new-console-template for more information



public class LinkedList
{

    public int nodeValue;
    public LinkedList next = null;


    public LinkedList(int nodeval)
    {
        nodeValue = nodeval;
    }

}





class TestSample
{
    public static LinkedList tail = null;
    public static LinkedList head = null;
    static void Main(string[] args)
    {


        LinkedList lList = new LinkedList(1);
        head = lList;
        tail = lList;

        AddNode(lList, 2);
        AddNode(lList, 3);
        AddNode(lList, 4);
        AddNode(lList, 5);

      ReverseList();


    }


    //Add at the end of the list
    public static void AddNode(LinkedList Currentnode, int newNodeVal)
    {
        // Head is created first time a node is added to the list
        if (head == null) {
            head = Currentnode;
        }


        // Go till the end of the chain and add a new node
        while (Currentnode != null && (Currentnode.next != null))
        {
            Currentnode = Currentnode.next;
        }

        var newlyaddednode = new LinkedList(newNodeVal);
        Currentnode.next = newlyaddednode;

        // Tail is updated at the end of addition of a new node
        tail = newlyaddednode;

    }


    //public static LinkedList ReverseList(LinkedList Currentnode)
    //{
    //    LinkedList previous = null;
    //    LinkedList curr = Currentnode;
    //    while (curr != null)
    //    {
    //        LinkedList next = Currentnode.next;
    //        Currentnode.next = previous;
    //        previous = curr;
    //        curr = next;

    //    }
    //    head = previous;

    //    return Currentnode;

    //}


    public static void ReverseList()
    {
        LinkedList prev = null, current = head, next = null;
        while (current != null)
        {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }





}
