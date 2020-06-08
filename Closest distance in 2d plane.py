#Python 3
def comp_x( l ):
    return l[0]

def comp_y( l ):
    return l[1]


def dist ( l1 , l2 ):
    return ( ((l1[0]-l2[0])**2) + ((l1[1]-l2[1])**2) )**(1/2)

def brute_force( l , s , e ):
    m = float("inf")
    temp =  0
    for i in range(s,e):
        for j in range( i+1,e ):
            temp = dist( l[i] , l[j] )
            if temp < m:
                m= temp
                
    return m


def strip_closest( strip , d ):
    m = d
    strip.sort(key=comp_y)
    temp = 0
    j=0
    for i in range (0,len(strip) ):
        j=i+1
        while ( j<len(strip) and abs(strip[j][1]-strip[i][1])<d ):
            temp = dist(strip[i],strip[j])
            if temp<m:
                m=temp
            j+=1;
    return m


def closest_points ( points , s , e ):
    n=e-s
    if (n<=5):
        return brute_force( points , s , e )
    mid = (e+s)//2
    midp = points[mid]
    dl = closest_points( points , s , mid )
    dr = closest_points( points , mid , e )
    d = 0
    if (dl<dr):
        d= dl
    else :
        d= dr
    strip = []
    for i in range (s,e):
        if ( abs( points[i][0] - midp[0] )<d ):
            strip.append( points[i] )
    temp = strip_closest( strip , d )
    if ( d<temp ):
        return d
    else :
        return temp



n = int (input());
l=[]
x= []
for i in range (n):
    x = list( map( int , input().split() ) )
    l.append(x)
l.sort( key = comp_x )
print( closest_points( l , 0 , len(l) ) )



