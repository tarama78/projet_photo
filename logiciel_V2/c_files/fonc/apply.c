void apply(t_p *p, char *retour)
{
    int		i;
    int		result;
    char	old_path[100];
    char	new_path[100];
    int		del_err;
    int		del_succ;
    int		ren_err;
    int		ren_succ;
    char	add_retour[100];

    del_err = 0;
    del_succ = 0;
    ren_err = 0;
    ren_succ = 0;
    i = -1;
    result = 1;
    while (++i < p->nb_p)
    {
	if (p->p[i].state == DELETE)
	{
	    get_full_name(p, i, old_path);
	    get_full_name_del(p, i, new_path);
	    printf(">>> delete :\n\t%s\n", old_path);
	    result = rename(old_path, new_path);
	    if (result == 0)
	    {
		printf("\tresult : SUCCESS\n");
		del_succ++;
	    }
	    else
	    {
		printf("\tresult : ERROR\n");
		del_err++;
	    }
	}
	else if (p->p[i].view == 1)
	{
	    get_full_name(p, i, old_path);
	    get_full_new_name(p, i, new_path);
	    if (strcmp(old_path, new_path) != 0)
	    {
		printf(">>> rename :\n\told name : %s\n\tnew name : %s\n",
		       old_path, new_path);
		result = rename(old_path, new_path);
		if (result == 0)
		{
		    printf("\tresult : SUCCESS\n");
		    ren_succ++;
		}
		else
		{
		    printf("\tresult : ERROR\n");
		    ren_err++;
		}
	    }
	}
    }
    printf(">>> result :\n\t%d file deleted with success\n"
	   "\t%d file deleted with error\n"
	   "\t%d file renamed with success\n"
	   "\t%d file renamed with eror\n"
	   "\ttotal :\n\t\t%d success\n\t\t%d error\n",
	   del_succ, del_err, ren_succ, ren_err,
	   (del_succ + ren_succ), (del_err + ren_err));
    sprintf(add_retour, "%d\n%d\n", (del_succ + ren_succ), (del_err + ren_err));
    strcat(retour, add_retour);
}
