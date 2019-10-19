void bubble_sort(int a[], int n){
    int i, j, t;
    for(i = 0; i<n-1; i++)
        for(j = n-1; j>i; j--)
            if(a[j-1]>a[j]){
                t = a[j]; a[j] = a[j-1]; a[j-1] = t;
            }
}

void selection_sort(int a[], int n){
    int i, j, t, lowest, lowkey;
    for(i = 0; i<n-1; i++){
        lowest = i;
        lowkey = a[i];
        for(j=i+1; j<n; j++)
            if(a[j]<lowkey){
                lowest = j;  lowkey = a[j];
            }
        t = a[i]; a[i] = a[lowest]; a[lowest] = t;
    }
}

void inertion_sort(int a[], int n){
    int i, j, t;
    for(i=1; i<n; i++){
        j = i;
        while(j>=1 && a[j-1]>a[j]){
            t = a[j]; a[j] = a[j-1]; a[j-1] = t;
            j--;
        }
    }
}

void shell_sort(int a[], int n){
    int h, i, j, t;
    for(h = 1 ; h<n/9; h=h*3+1)
        ;
    for(; h>0; h/=3){
        for(i = h; i<n; i++){
            j = i;
            while(j>=h && a[j-h]>a[j]){
                t = a[j]; a[j] = a[j-h]; a[j-h] = t;
                j -= h;
            }
        }                               
    }
}

int partition(int a[], int l, int r){
    int i, j, pivot, t;
    i = l-1;
    j = r;
    pivot = a[r];
    for(;;){
        while(a[++i]<pivot)
            ;
        while(i< --j && pivot < a[j])
            ;
        if(i >= j)
            break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[i]; a[i] = a[r]; a[r] = t;
    return i;
}

void quick_sort_1(int a[], int l, int r){
    int v;
    if(l>=r)
        return;
    v = partition(a, l, r);
    quick_sort_1(a, l, v-1);
    quick_sort_1(a, v+1, r);
}

void quick_sort2(int a[], int n){
    int l, r, v;
    int low[30], high[30];
    int sp;
    low[0] = 0;
    high[0] = n-1;
    sp = 1;
    while(sp>0){
        sp--;
        l = low[sp];
        r = high[sp];
        if(l>r)
            ;
        else{
            v = partition(a, l, r);
            if (v-l<r-v){
                low[sp] = v+1;
                high[sp++] = r;
                low[sp] = l;
                high[sp++] = v-1;
            }else{
                low[sp] = l;
                high[sp++] = v-1;
                low[sp] = v+1;
                high[sp++] = r;
            }
        }
    }
}

void quick_sort(int a[], int n){
    quick_sort_1(a, 0, n-1);
}

#define MAX_ELEMENTS 10000
int b[MAX_ELEMENTS];

void merge_sort_array(int a[], int low, int high){
    int mid, i, j, k;
    if(low >= high)
        return;
    mid = (low+high)/2;
    merge_sort_array(a, low, mid);
    merge_sort_array(a, mid+1, high);
    for(i = low; i<=mid; i++)
        b[i] = a[i];
    for(i = mid+1, j = high; i <= high; i++, j--)
        b[i] = a[j];
    i = low; j = high;
    for(k = low; k <=high; k++)
        if(b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j--];
}

struct node{
    int value;
    struct node *next;
};

struct node *merge_list(struct node *a, struct node *b){
    struct node head, *p;
    p = &head;
    while(a != NULL && b != NULL){
        if(a->value <= b->value){
            p->next = a;
            p = a;
            a = a->next;
        }else{
            p -> next = b;
            p = b;
            b = b->next;
        }
    }
    if(a == NULL)
        p -> next = b;
    else
        p -> next = a;

    return head.next;
}

struct node *merge_sort_list(struct node *x){
    struct node *a, *b, *p;
    if(x == NULL || x->next == NULL)
        return x;
    a = x;
    b = x->next;
    if(b != NULL)
        b = b->next;
    while(b!=NULL){
        a = a->next;
        b = b->next;
        if(b!=NULL)
            b = b->next;
    }
    p = a->next; a->next = NULL;

    return merge_list(merge_sort_list(x), merge_sort_list(p));
}


#define MAX_HEAP 10000
int n = 1000;
int a[MAX_HEAP+1];


void downheap(){
    int i, j;
    int val;
    val = a[1];
    i = 1;
    while(i <= n/2){
        j = i*2;
        if(j+1 <= n && a[j]>a[j+1])
            j++;
        if(val<=a[j])
            break;
        a[i] = a[j];
        i = j;
    }
    a[i] = val;
}

int delete_min(){
    int val;
    if(n<1){
        fprintf(stderr, "ヒープが空です\n");
        exit(1);
    }
    val = a[1];
    a[1] = a[n--];
    downheap();
    return val;
}

void upheap(int x){
    int val;
    val = a[x];
    while(x>1 && a[x/2] > val){
        a[x] = a[x/2];
        x /= 2;
    }
    a[x] = val;
}

void insert(int elem){
    if(n >= MAX_HEAP){
        fprintf(stderr, "これ以上ヒープに要素を登録できません\n");
        exit(1);
    }
    a[++n] = elem;
    upheap(n);
}