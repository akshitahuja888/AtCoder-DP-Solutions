class Solution {
public:
    struct Node {
        Node* left;
        Node* right;
        long long int data;
        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    unordered_map<long long int, long long int> subCount;
    long long int helper(Node* root)
    {
        if (root == NULL) return 0;

        int l = helper(root->left);
        int r = helper(root->right);

        subCount[root->data] = l + r + 1;
        return l + r + 1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        long long int n = parents.size();

        vector<Node*> tree(n);
        for (int i = 0; i < n; i++)
        {
            tree[i] = new Node(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (parents[i] != -1)
            {
                if (tree[parents[i]]->left == NULL)
                    tree[parents[i]]->left = tree[i];
                else
                    tree[parents[i]]->right = tree[i];
            }
        }

        Node* root = tree[0];
        helper(root);
        unordered_map<long long int, long long int> score;

        if (tree[0]->left != NULL and tree[0]->right != NULL)
        {
            long long int s1 = subCount[tree[0]->left->data];
            long long int s2 = subCount[tree[0]->right->data];
            score[s1 * s2]++;
        } else if (tree[0]->left == NULL and tree[0]->right != NULL)
        {
            long long int s1 = subCount[tree[0]->right->data];
            score[s1]++;
        } else if (tree[0]->left != NULL and tree[0]->right == NULL)
        {
            long long int s1 = subCount[tree[0]->left->data];
            score[s1]++;
        }
        for (int i = 1; i < n; i++)
        {
            if (tree[i]->left != NULL and tree[i]->right != NULL)
            {

                long long int s1 = subCount[tree[i]->left->data];
                long long int s2 = subCount[tree[i]->right->data];
                long long int s3 = subCount[0] - subCount[i];
                score[s1 * s2 * s3]++;
            } else if (tree[i]->left == NULL and tree[i]->right == NULL)
            {
                score[n - 1]++;
            } else {
                if (tree[i]->left != NULL and tree[i]->right == NULL)
                {
                    long long int s1 = subCount[tree[i]->left->data];
                    long long int s2 = subCount[0] - subCount[i];
                    score[s1 * s2]++;
                } else if (tree[i]->left == NULL and tree[i]->right != NULL)
                {
                    long long int s1 = subCount[tree[i]->right->data];
                    long long int s2 = subCount[0] - subCount[i];
                    score[s1 * s2]++;
                }
            }
        }
        long long int mxs = -1;
        for (auto x : score)
        {
            mxs = max(mxs, x.first);
        }
        return score[mxs];
    }
};