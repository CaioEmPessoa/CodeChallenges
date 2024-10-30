from json import dumps

def bin_search(g_info:dict, value:int) -> int:
    pass

def quick_sort(g_info:dict) -> dict:

    if len(g_info) <= 1:
        return g_info

    g_list = [g_info[r] for r in g_info]
    s_list = [r for r in g_info]

    pyvot_g = g_list[len(g_list)-1]
    pyvot_s = s_list[len(g_list)-1]
    
    smaller = {}
    smaller[pyvot_s] = pyvot_g

    bigger = {}


    i = 0
    while i < len(g_list):

        if pyvot_g > g_list[i]:
            smaller[s_list[i]] = g_list[i]
        
        if pyvot_g < g_list[i]:
            bigger[s_list[i]] = g_list[i]
        
        i+=1

    return quick_sort(bigger) | quick_sort(smaller)

def normalize_data(g_info: dict) -> dict:
    grade_sum_info = {}
    for s in g_info:
        grade_sum_info[s] = 0 # kinda ungly
        for grade in g_info[s]:
            try:
                grade_sum_info[s] += grade
            except: # it says that its required to do that on the requirements
                grade_sum_info[s] += int(grade)

    return grade_sum_info

alunos = {'000': [65, 68, 1, 50, 34, 88],
          '001': [100, 11, 54, 45, 96, 6],
          '002': [56, '13', 1, 7, 19, 20],
          '003': [22, 9, 22, 87, 44, 65],
          '004': [98, 76, 24, 56, '54', 43],
          '005': [18, 73, 95, 29, 31, 8],
          '006': [94, '78', 14, 72, 46, 29],
          '007': [50, 96, 71, 53, 83, 100],
          '008': [83, 28, 19, 25, 4, 82],
          '009': [9, 67, 65, 90, 6, 8]}

g_info = normalize_data(alunos)
q_sort = quick_sort(g_info)


print(alunos)
print(dumps(q_sort, indent=4))
print("fim")


