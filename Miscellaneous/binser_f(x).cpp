// binary search with max evaluation function ^_^
while (1) {
	int sal, res = -1, lm = -1;
	scanf("%d", &sal);
	
	int low = 1, high = solve(sal), mid;
	while (low <= high) {
		mid = (low + high)/2;
		if (lm == mid) break;

		int numFence = numberOfFence(mid);
		if (numFence == sal) 
			res = mid, high = mid;
		else if (numFence < sal)
			res = mid, low = mid+1;
		else if (numFence > sal)
			high = mid;

		lm = mid;
	}
	printf("%d\n", res);
}