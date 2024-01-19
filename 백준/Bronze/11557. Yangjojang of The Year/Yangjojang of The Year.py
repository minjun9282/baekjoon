T = int(input())
school_names = []
school_alcohols = []
for i in range(T):
    N = int(input())
    for j in range(N):
        school, alcohols = input().split()
        school_names.append(school)
        school_alcohols.append(int(alcohols))
    max_index = school_alcohols.index(max(school_alcohols))
    print(school_names[max_index])
    school_names.clear()
    school_alcohols.clear()