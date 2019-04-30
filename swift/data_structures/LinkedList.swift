
class Node
{
    var data: Int
    var next: Node

    init(next: Node, data: Int)
    {
        self.data = data
        self.next = next
    }
}

class LinkedList
{
    var head: Node

    init()
    {
        self.head = nil
    }
}

