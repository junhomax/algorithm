#include <cstdio>
#include <cstring>

#define maxc 501
#define maxa 100001
#define maxlen 41
#define EMPTY (-1)
#define TRUE 1
#define FALSE 0

typedef struct st
{
	char car_name[maxlen];
	int car_cost;			//원가
	int initial_cost;		//초기 대여 비용
	int cost_per_kilo;		//주행거리 1km 당 추가 비용
}INFO1;
INFO1 car_info[maxc];

typedef struct _st
{
	int inconsistency_flag;
	char agent_name[maxlen];
	int rented_car_index;
	int total_cost;
}INFO2;
INFO2 agent_info[maxa];

int Listed[maxc];

int main()
{
	int T;
	int n, m;
	int i, j, s;
	int agent_count;
	int p, d;

	char Name[41], event;

	scanf("%d\n", &T);
	while(T--)
	{
		scanf("%d %d\n", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s %d %d %d\n", car_info[i].car_name, &car_info[i].car_cost, &car_info[i].initial_cost, &car_info[i].cost_per_kilo);

		agent_count = 0; 
		for (i = 0; i < m; i++)
		{
			scanf("%*d %s %c\n", Name, &event); 
			for (s = 0; s < agent_count && strcmp(Name, agent_info[s].agent_name) != 0; s++); 
			if (s == agent_count)
			{
				strcpy(agent_info[agent_count++].agent_name, Name);
				agent_info[s].total_cost = 0;
				agent_info[s].rented_car_index = EMPTY; 
				agent_info[s].inconsistency_flag = 0;
			}

			switch (event)
			{
			case 'p':
				if (agent_info[s].rented_car_index != EMPTY) 
					agent_info[s].inconsistency_flag = 1;
				scanf("%s\n", Name);
				for (j = 0; j < n && strcmp(Name, car_info[j].car_name) != 0; j++);
				agent_info[s].rented_car_index = j;
				agent_info[s].total_cost += car_info[j].initial_cost;
				break;
			case 'a':
				if (agent_info[s].rented_car_index == EMPTY) 
					agent_info[s].inconsistency_flag = 1;
				scanf("%d\n", &p);
				agent_info[s].total_cost += (int)((p * car_info[agent_info[s].rented_car_index].car_cost + 99) / 100); 
				break;
			case 'r':
				if (agent_info[s].rented_car_index == EMPTY) 
					agent_info[s].inconsistency_flag = 1;
				scanf("%d\n", &d);
				agent_info[s].total_cost += d * car_info[agent_info[s].rented_car_index].cost_per_kilo;
				agent_info[s].rented_car_index = EMPTY;
				break;
			}
		}

		for (i = 0; i < agent_count; i++)
			Listed[i] = FALSE;
		for (i = 0; i < agent_count; i++)
		{
			s = -1;
			for (j = 0; j < agent_count; j++)
				if (!Listed[j] && (s == -1 || strcmp(agent_info[j].agent_name, agent_info[s].agent_name) < 0))
					s = j;

			printf("%s ", agent_info[s].agent_name);
			if (!agent_info[s].inconsistency_flag && agent_info[s].rented_car_index == EMPTY)	
				printf("%d\n", agent_info[s].total_cost);
			else
				printf("INCONSISTENT\n");
			Listed[s] = TRUE;
		}
	}
	return 0;
}

