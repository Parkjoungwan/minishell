void	builtin_pwd(t_list **envhead)
{
	char	*str;

	str = ms_getenv(*envhead, "PWD");
	if (str)
		printf("%s\n", str);
	ms_print_error(head, NULL, 0);
}
