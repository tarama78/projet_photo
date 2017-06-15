void next_p(t_p *p)
{
    p->p_act++;
    if (p->p_act >= p->nb_p)
	p->p_act = 0;
    p->p_change = 1;
    p->letter_change = 1;
    p->p[p->p_act].view = 1;
}

void prev_p(t_p *p)
{
    p->p_act--;
    if (p->p_act < 0)
	p->p_act = p->nb_p - 1;
    p->p_change = 1;
    p->letter_change = 1;
    p->p[p->p_act].view = 1;
}
