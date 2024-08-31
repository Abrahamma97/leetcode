bool findloop(int idx, int *visited, int cmap[][5000], int preqcount[]) {
	if(visited[idx] > 0) {
		return true;
	}

	if(visited[idx] == 0) {

		visited[idx] = 1;
		for(int i = 0; i < preqcount[idx]; i++) {

			if(findloop(cmap[idx][i], visited, cmap, preqcount)) {
				return true;
			}

		}
		visited[idx] = -1;
	}
	return false;
}




bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
	int cmap[2001][5000] = {};
	int preqcount[2001] = {};
	int visited[2001] = {0};
	int course;
	int prereq;



	for(int i = 0; i < prerequisitesSize; i++) {
		course = prerequisites[i][0];
		prereq = prerequisites[i][1];

		cmap[course][preqcount[course]++] = prereq;
	}

	for(int i =0; i < numCourses; i++) {
		if(findloop(i, visited, cmap,preqcount)) {
			return false;
		}

	}

	return true;
}


