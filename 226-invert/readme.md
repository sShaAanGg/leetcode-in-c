# Invert Binary Tree
- 將左右子節點交換
  - 透過 function 須注意傳入參數型別為 `TreeNode **` (如果透過 pass-by-value 方式)
    - 裡面宣告 `TreeNode *temp = *left;` 來暫時儲存 left child node 的位址

