/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();

        if (root == null)
           return res;
        
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while (!q.isEmpty())
        {
            int q_sz = q.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < q_sz; i++)
            {
                TreeNode cur = q.poll();

                level.add(cur.val);

                if (cur.left != null)
                  q.offer(cur.left);
                if (cur.right != null)
                  q.offer(cur.right);
            }

            res.add(0, level);
        }

        return res;
        
    }
}