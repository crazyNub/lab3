#include "cl_application.h"

cl_application::cl_application()
{
	set_object_name("root");
	
	set_state(1);
}


void cl_application::bild_tree_objects()
{
	p_ob_1 = new cl_1();
	p_ob_1->set_object_name("ob_1");
	p_ob_1->set_parent(this);
	p_ob_11=p_ob_1;
	
	p_ob_2 = new cl_2();
	p_ob_2->set_object_name("ob_2");
	p_ob_2->set_parent(p_ob_1);
	
	p_ob_3 = new cl_3();
	p_ob_3->set_object_name("ob_3");
	p_ob_3->set_parent(p_ob_2);
	p_ob_33=p_ob_3;
	
	p_ob_4 = new cl_4();
	p_ob_4->set_object_name("ob_4");
	p_ob_4->set_parent(p_ob_2);
	
	p_ob_4 = new cl_4();
	p_ob_4->set_object_name("ob_5");
	p_ob_4->set_parent(p_ob_1);
	p_ob_55=p_ob_4;
	
	p_ob_1 = new cl_1();
	p_ob_1->set_object_name("ob_6");
	p_ob_1->set_parent(this);
	
	p_ob_2 = new cl_2();
	p_ob_2->set_object_name("ob_7");
	p_ob_2->set_parent(this);
	
	p_ob_3 = new cl_3();
	p_ob_3->set_object_name("ob_8");
	p_ob_3->set_parent(p_ob_2);
	
	last_obj_name = p_ob_3->get_object_name();
}

int cl_application::exec_app()
{
	show_tree((cl_base*)this, 0, last_obj_name);
	
	p_ob_11->set_connect(SIGNAL_D(p_ob_11->signal_1), p_ob_55, HENDLER_D (p_ob_55->hendler_1));
	p_ob_11->set_connect(SIGNAL_D(p_ob_11->signal_2), p_ob_55, HENDLER_D (p_ob_55->hendler_2));
	p_ob_11->set_connect(SIGNAL_D(p_ob_11->signal_2), p_ob_33, HENDLER_D (p_ob_33->hendler_1));
	
	
	int interaction;
	string text;
	cin>>interaction;
	while (interaction)
	{
		cin>>text;
		switch (interaction)
		{
			case 1: p_ob_11->emit_signal(SIGNAL_D(p_ob_11->signal_1), text);
				break;
			case 2: p_ob_11->emit_signal(SIGNAL_D(p_ob_11->signal_2), text);
				break;
			case 3: p_ob_11->emit_signal(SIGNAL_D(p_ob_11->signal_2), text);
				break;
		}
		cin>>interaction;
	}
	
	return 0;
}
