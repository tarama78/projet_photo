void apply(t_photos *photos)
{
    int		i;
    char	old_path[100];
    char	new_path[100];

    (void)new_path;
    i = -1;
    while (++i < photos->nb_photos)
    {
	if (photos->photos[i].state == DELETE)
	{
	    get_full_name(photos, i, old_path);
	    get_full_name_del(photos, i, new_path);
	    printf(">>> delete :\n\t%s\n", old_path);
	    printf("\tresult (0 = success) : %d\n", rename(old_path, new_path));
	}
	else if (photos->photos[i].view == 1)
	{
	    get_full_name(photos, i, old_path);
	    get_full_new_name(photos, i, new_path);
	    if (strcmp(old_path, new_path) != 0)
	    {
		printf(">>> rename :\n\told name : %s\n\tnew name : %s\n",
		       old_path, new_path);
		printf("\tresult (0 = success) : %d\n", rename(old_path, new_path));
	    }
	}
    }
}
