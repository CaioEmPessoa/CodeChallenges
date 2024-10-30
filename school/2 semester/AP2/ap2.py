from json import dumps

RA = "2400540"

def save_data(data:any, r_id:str):
    with open(f"{RA}_resp_{r_id}.txt", "w") as write_file:
        to_write = f"[\n    {",\n    ".join(data)}\n]"
        write_file.write(to_write)

def bin_search(g_info:dict, value:int, minmax:tuple=False) -> int:
    # so the first call don't need to specify size of list
    if minmax == False:
        minmax = (0, len(g_info)-1)

    g_list = [g_info[g] for g in g_info]
    s_list = [r for r in g_info]
    min, max = minmax

    mid = (min + max) // 2

    if value == g_list[mid]:
        return s_list[mid], mid
    
    elif g_list[mid] > value :
        return bin_search(g_info, value, (mid, max))
    
    elif g_list[mid] < value :
        return bin_search(g_info, value, (min, mid))

def quick_sort(g_info:dict) -> dict:

    if len(g_info) <= 1:
        return g_info

    g_list = [g_info[g] for g in g_info]
    s_list = [s for s in g_info]

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
            except: # it says that its required to do that CHECK
                grade_sum_info[s] += int(grade)

    return grade_sum_info


s_info_list = [{
        '000': [95, 16, 19, 44, 90, 67],
        '001': [21, 20, 27, 40, 84, 41],
        '002': [94, '16', 27, 97, 75, 32],
        '003': [79, 58, '1', 63, 88, 20],
        '004': [65, 74, 65, 7, '95', 70],
        '005': [73, 92, 77, 98, '73', 71],
        '006': [18, 70, 25, 5, 65, 83],
        '007': [31, 86, 42, '73', 42, 34],
        '008': [81, 46, '73', 84, 31, 82],
        '009': [21, 90, 15, 62, '13', 2],
        '010': [5, 16, 47, 19, '96', 19],
        '011': [74, 70, 74, 30, 61, '60'],
        '012': [70, 36, 24, 53, 17, 16],
        '013': [62, 58, 8, 82, 38, 57],
        '014': [32, 58, 81, 87, 64, 53],
        '015': [48, 60, 78, 12, 79, 5],
        '016': [73, 45, 9, 12, 39, 31],
        '017': [5, 54, 89, 60, 35, 56],
        '018': [23, 76, 44, 67, 19, 13],
        '019': ['77', 61, 97, 19, 37, 55]},
        {
        '000': [99, 54, 76, 7, 46, 79],
        '001': [61, 92, 58, 92, 29, '8'],
        '002': [66, 12, 38, 12, 37, 28],
        '003': [19, 57, 31, 36, 74, 34],
        '004': [72, 32, 81, 9, '15', 72],
        '005': [22, 50, 95, 67, 23, 32],
        '006': [12, 1, 51, 12, 1, 64],
        '007': [82, 23, 30, '29', 32, 74],
        '008': [78, 31, 52, 68, 57, 1],
        '009': ['46', 19, 98, 22, 92, 33],
        '010': [20, 70, 30, '88', 37, 78],
        '011': [12, 65, 45, 17, 35, '73'],
        '012': [86, 57, 82, 26, 36, '95'],
        '013': [32, 91, 67, 82, '21', 28],
        '014': [33, '37', 12, 90, 25, 97],
        '015': [3, 82, '79', 70, 30, 43],
        '016': [19, 65, 84, 76, '72', 17],
        '017': [65, 61, 96, 42, 54, 49],
        '018': [12, 39, 51, 83, 68, '96'],
        '019': [26, 10, 33, 54, 36, 30]
        }
    ]

s_info_id = 1
for s_info in s_info_list:
    g_info = normalize_data(s_info)
    q_sort = quick_sort(g_info)
    bin_s = bin_search(q_sort, q_sort['001'])

    q_sort_s_list = [s for s in q_sort]

    save_data(q_sort, s_info_id)
    s_info_id += 1
    print("\n\n")

'''
print("\n     ######## ORIGINAL INFO ########       \n")
print(alunos)
print("\n     ######## SORTED INFO ########     \n")
print(dumps(q_sort, indent=4))
print("\n     ######## BIN_SEARCH RESULT ########       \n")
print(bin_s)
print("\n     ######## END ########       \n")
'''

