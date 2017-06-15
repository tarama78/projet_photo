void change_p(t_p *p)
{
    int num_p;

    num_p = my_getnbr(p->nb_depl);
    if (num_p <= p->nb_p)
    {
	p->p_act = num_p - 1;
	p->nb_depl[0] = '\0';
	p->letter_change = 1;
	p->p_change = 1;
	p->p[p->p_act].view = 1;
    }
}

void next_p(t_p *p)
{
    p->p_act++;
    if (p->p_act >= p->nb_p)
	p->p_act = 0;
    p->p_change = 1;
    p->letter_change = 1;
    p->p[p->p_act].view = 1;
    p->cont_autosave++;
}

void prev_p(t_p *p)
{
    p->p_act--;
    if (p->p_act < 0)
	p->p_act = p->nb_p - 1;
    p->p_change = 1;
    p->letter_change = 1;
    p->p[p->p_act].view = 1;
    p->cont_autosave--;
}
