
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def Values(self):
        current = self
        while(current != None):
            print(current.val)
            current = current.next

class Solution:
    def MergeKLists(self, lists:list) -> ListNode:
        merged = None
        if len(lists) == 0:
            return merged
        elif len(lists) == 1:
            return lists[0]
        else:
            merged = lists.pop(0)
            while len(lists) > 0:
                merged = self.MergeTwoLists(merged, lists[0])
                #
                lists.pop(0)
        return merged

    def MergeTwoLists(self, left:ListNode, right:ListNode) -> ListNode:
        #
        merged = ListNode(-1)
        last = merged
        #
        while left != None and right != None:   
            if left.val < right.val:
                last.next = left
                last = last.next
                left = left.next
            elif left.val > right.val:
                last.next = right
                last = last.next
                right = right.next
            elif left.val == right.val:
                last.next = left
                last = last.next
                left = left.next
                last.next = right
                last = last.next
                right = right.next
        #
        if left != None:
            last.next = left
        if right != None:
            last.next = right
        #
        return merged.next

if __name__ == "__main__":
    test = list()
    node1 = ListNode(1)
    node1.next = ListNode(4)
    node1.next.next = ListNode(5)
    test.append(node1)

    node2 = ListNode(1)
    node2.next = ListNode(3)
    node2.next.next = ListNode(4)
    test.append(node2)

    node = ListNode(2)
    node.next = ListNode(6)
    test.append(node)
    
    solution = Solution()
    solution.MergeKLists(test).Values()
    