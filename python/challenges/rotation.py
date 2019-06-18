
m1=[['01','02','03','04'],['05','06','07','08'],['09','10','11','12']]

def pretty(matrix):
    for e in matrix:
        print(e)

pretty(m1)
print('\n')

def rotate(matrix):
    size=len(matrix)-1
    for i_list in range(len(matrix)):
        for i_element in range(len(matrix)):
            temp=matrix[0][i_element]
            matrix[0][i_element]=matrix[size-i_element][0]
            matrix[size-i][0]=matrix[size][size-i_element]
            matrix[size][size-i_element]=matrix[i_element][size]
            matrix[i_element][size]=temp

pretty(m1)

