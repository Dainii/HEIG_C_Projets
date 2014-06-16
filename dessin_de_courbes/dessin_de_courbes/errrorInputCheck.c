

int errorInputCheck(double minX, double maxX, double stepX, double alternateStepX, double minY, double maxY, double stepY, double alternateStepY, unsigned long width, unsigned long height, unsigned int margin)
{
	if (stepX <= 0 || stepY <= 0 || alternateStepX <= 0 || alternateStepY <= 0 )
	{
		return 1001;
	}

	if (minX > 0 || minY > 0)
	{
		return 1002;
	}

	if (maxX < 0 || maxY < 0)
	{
		return 1003;
	}

	if (height < (2*margin) || width < (2*margin))
	{
		return 1004;
	}

	if ((width * height) < 65535)
	{
		return 1005;
	}

	if (margin <= 0)
	{
		return 1006;
	}
	if (minX == maxX || minY == maxY)
	{
		return 1006;
	}

	return 0;
}