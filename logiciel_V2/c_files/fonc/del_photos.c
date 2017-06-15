void del_p_id(t_p *p, int id)
{
    p->p[id].state = DELETE;
}

void del_p_name(t_p *p, char *name)
{
    int		i;

    i = -1;
    while (++i < p->nb_p)
	if (p->p[i].name == name)
	    break;
    del_p_id(p, i);
}
