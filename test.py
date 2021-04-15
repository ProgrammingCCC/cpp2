def convert_data(dicList, keys):
    for dic in dicList:
        for k, v in dic.items():
            if k in keys:
                dic[k] = int(v)
    return dicList
    
