#include "kruskal.h"

int main()
{
	struct node edge[size * size / 2];
	while (1) 
	{
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		char x, y;
		int m, weight;
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			//cin >> x >> m;
			scanf("%c %d", &x, &m);    
			//printf("%c %d ", x, m);
			for (int j = 0; j < m; j++) {
				//cin >> y >> weight;
				scanf("%c %d", &y, &weight);
				//printf("%c %d ", y, weight);    
				edge[cnt].start = x - 'A';
				edge[cnt].end = y - 'A';
				edge[cnt].val = weight;
				cnt++;
			}
		}

		sort(edge, edge + cnt, cmp); //对边按权从小到大排序 
		cout << kruskal(cnt) << endl;
	}
}