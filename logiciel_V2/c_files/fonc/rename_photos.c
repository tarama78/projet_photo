void rename_p_name(t_p *p, char *name, char *new_name)
{
    int		id;
    int		i;

    id = get_p(p, name);
    if (id == -1)
	printf("rename_p : nom <%s> invalide", name);
    else
    {
	if (p->p[id].state == DELETE)
	    printf("*** rename_p : impossible de renomer la p \
		elle a ete supprimer ***\n");
	else
	{
	    i = -1;
	    while (++i < (int)strlen(name))
		p->p[id].new_name[i] = new_name[i];
	    p->p[id].state = NEW_NAME;
	}
    }
}

void rename_p_id(t_p *p, int id, char *new_name)
{
    rename_p_name(p, p->p[id].name, new_name);
}
