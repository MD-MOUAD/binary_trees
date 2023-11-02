
		if (!left && right)
		{
			free2(queue);  /* If a node has a left child*/
			return (0);   /* but no right child */
		}
		if (!left && !right)
		{
			while (queue->front)
			{
				btree_node = dequeue(queue);
				if (btree_node->left || btree_node->right)
				{
					free2(queue);
					return (0);
				}
			}
			free2(queue);
			return (1);
		}
		if (left && !right && (left->left || left->right))
		{
			free2(queue);  /* If a node has a left child but no right child */
			return (0);  /* and is not in the last level */
		}
		if (left && !right && last_except == 1)
		{
			free2(queue);  /* If a node has a left child but ni right child */
			return (0);  /* and is in the last level for the second time */
		}
		if (left && !right)
			last_except = 1;
		if (left)
			enqueue(queue, left);
		if (right)
			enqueue(queue, right);
