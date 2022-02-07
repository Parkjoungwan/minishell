void	builtin_env(t_list **envhead)
{
	t_env	*ptr;
	t_list	*head;

	if (!envhead)
		return ;
	head = *envhead;
	while (head)
	{
		ptr = (t_env *)(head->content);
		printf("%s=", ptr->name);
		if (ptr->value)
			printf("%s\n", ptr->value);
		else
			printf("\n");
		head = head->next;
	}
	ms_print_error(list, NULL, 0);
	return ;
}
