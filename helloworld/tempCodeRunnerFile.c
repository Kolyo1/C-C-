GraduationYear year;
    printf("Enter number of classes: ");
    scanf("%d", &year.classCount);
    if (year.classCount > 5 || year.classCount < 0)
    {
        printf("Number of classes cannot exceed 5 and be bellow 0\n");
        return 0;
    }
        for (int i = 0; i < year.classCount; i++)
    {
        inputStudent(&year.class[i]);
    }
    printf("Average GPA of each class:\n");
    for (int i = 0; i < year.classCount; i++)
    {
        printf("Class %s: %.2f\n", year.class[i].className, classGPA(year.class[i]));
    }
    printf("Average GPA of the year: %.2f\n", yearGPA(year));