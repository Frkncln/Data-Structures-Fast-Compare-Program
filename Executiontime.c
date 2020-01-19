#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 20
struct stack_t{
	
	int data;
	struct stack_t *next;
};
typedef struct stack_t stack;
 
struct queue_t{
	
	int data;
	struct queue_t *next;
};
 typedef struct queue_t queue;
 
 
struct  bst_t{
    struct bst_t *left;
    int data;
    struct bst_t *right;
};
typedef struct bst_t bst;


 

bst  *ekle(bst **agac,int x){//ekleme yapma
	
	
	if((*agac)==NULL){
		
		(*agac)=(bst*)malloc(sizeof(bst));
		(*agac)->left=NULL;
		(*agac)->right=NULL;
		(*agac)->data=x;
		return (*agac);
	}
	
	if((*agac)->data<x){//suanki datadan büyükse saða eklenir
	
		(*agac)->right=ekle(&(*agac)->right,x);
		return (*agac);
		}
	if((*agac)->data>x){//suanki datadan küçükse sola eklenir
	
		(*agac)->left=ekle(&(*agac)->left,x);
		return (*agac);
		}
	
	}




void orderbst(bst *tree){// bst order yardýmcý fonksiyonu
		if(tree==NULL){
			return;
		}
		
		orderbst(tree->right);//en son saða kadar gitcek recursion þekilde solun en üstüne kadar print
		
		printf("%d ",tree->data);
		
		orderbst(tree->left);//soltarafta gitcek sona kadar
		
	}
	
	
void fill_structures(stack **stack_ ,queue **queue_ ,bst **bst_ ,int data[20]){
	int i=0;
	double t_stack,t_queue,t_bst;
	clock_t stack1,queue1, bst1;
  
	
	stack1=clock();
  
	for(i=0;i<SIZE;i++){//stack doldurma
	
	if(*stack_==NULL){//boþsa yer açtýk
		(*stack_)=malloc(sizeof(stack));
		(*stack_)->data=data[i];
		(*stack_)->next=NULL;
	}
	
	else{
	
    stack *temp;
	  temp=(stack*)malloc(sizeof(stack));
		temp->data=data[i];
		temp->next=(*stack_);
		(*stack_)=temp;
	
			
		}
	} 
	stack1=clock()-stack1;
	t_stack=((double)(stack1))/CLOCKS_PER_SEC*1000;

  //********queue doldurma kýsmý
    queue1=clock();
    
	for(i=0;i<SIZE;i++){  
	
    if( (*queue_) == NULL){//boþsa yer açtýk
      (*queue_)=(queue*)malloc(sizeof(queue));
      (*queue_)->data=data[i];
    }
    else{
    
      queue *temp;
      temp=(queue*)malloc(sizeof(queue));
      temp->data=data[i];
      temp->next=(*queue_);
      (*queue_)=temp;
      
      }
      
	}	
  	queue1=clock()-queue1;
	t_queue=((double)(queue1));
	//bst doldurma kýsmý
	 bst1=clock();
   for(i=0;i<SIZE;i++){
		//(*bst_)=ekle(&(*bst_),data[i]);
		
	}
	bst1=clock()-bst1;
	t_bst=((double)(bst1));

  	printf("\nFILLING TIMES\n");
  	printf("\nStructures  STACK     QUEUE       BST \n");
	printf("Exec.Time    %.3lf     %.3lf    %.3lf\n",t_stack,t_queue,t_bst);

}





void ordered_print(stack * stack_,queue * queue_, bst * bst_){// print them in descending order
	int tmp,i=0,bstcount=0;
	stack *temp,*temp2,*temp3;
	temp=stack_;
	temp3=stack_;	
	queue *qtemp,*qtemp2,*qtemp3;
  	qtemp=queue_;
	qtemp3=queue_;
  	bst *bstemp,*bstemp2,*bstemp3;
  	bstemp=bst_;
  	bstemp3=bst_;
  	
	double t_stack,t_queue,t_bst;//time deðiþkenleri
	clock_t stack1,queue1, bst1;
	
	stack1=clock();
	//------------------------------------******stack order kýsmý****
	printf("\nSTACK ORDER\n");
		while(temp!=NULL){
			
			temp2=temp3;
			
			while(temp2->next!=NULL){
				
				if(temp2->data < temp2->next->data){
					
					
				tmp=temp2->data;	
				temp2->data=temp2->next->data;
				temp2->next->data=tmp;
			}
			temp2=temp2->next;	
		}
		temp=temp->next;
	}
	temp=temp3;
	while(temp!=NULL){
			printf("%d) %d ", i+1, temp->data);
            temp = temp->next;
            i++;
		}
	stack1=clock()-stack1;
	t_stack=((double)(stack1));
	
		
		
	//------------------------------***************queue order kýsmý***********
	queue1=clock();
	printf("\n\nQUEUE ORDER\n");
	while(qtemp!=NULL){
			qtemp2=qtemp3;
			
			while(qtemp2->next!=NULL){
				
				if(qtemp2->data < qtemp2->next->data){
					
				tmp=qtemp2->data;	
				qtemp2->data=qtemp2->next->data;
				qtemp2->next->data=tmp;
			}
			qtemp2=qtemp2->next;	
		}
		qtemp=qtemp->next;
	}
	qtemp=qtemp3;
  i=1;
	while(qtemp!=NULL){
			printf("%d) %d ", i, qtemp->data);
            qtemp = qtemp->next;
            i++;
		}
		queue1=clock()-queue1;
		t_queue=((double)(queue1));
		

	
	//---------------------------------**********bst order kýsmý******
	bst1=clock();
	printf("\n\nBST ORDER\n");
	qtemp=qtemp3;
  	i=1;
	while(qtemp!=NULL){
			printf("%d) %d ", i, qtemp->data);
            qtemp = qtemp->next;
            i++;
		}
	orderbst(bst_);
	
	bst1=clock()-bst1;
	t_bst=((double)(bst1));
	
  printf("\n\nORDER TIMES");
	printf("\nStructures  STACK     QUEUE       BST \n");
	printf("Exec.Time    %.3lf     %.3lf    %.3lf\n",t_stack,t_queue,t_bst);
}


void search(stack *stack_, queue * queue_, bst *bst_, int val_to_search){//belli deðeri search ve kaçýncý stepde bulunduðu
	int stackstep=0,questep=0,bststep=0,counter=0;
	bst *temp;
	temp=bst_;
	while (stack_!=NULL){ //--*******************************-stack search kýsmý************-----
		
		if(stack_->data!=val_to_search){
			stack_=stack_->next;
			stackstep++;
		}
		
	if(stack_->data == val_to_search){
		counter++;
		}
		
	}
	
	if(counter>0){
		printf("%d result founded on %d. step\n",counter,stackstep);
	}
	else{
		printf("%d not found in stack\n",val_to_search);
	}
	
	counter=0;
	
while (queue_!=NULL){//-*******************************----------queue search kýsmý**********
		
		if(queue_->data!=val_to_search){
			queue_=queue_->next;
			questep++;
		}
		
	if(queue_->data == val_to_search){
		counter++;
		}
		
	}
	
	if(counter>0){
		printf("%d result founded on %d. step\n",counter,questep);
	}
	else{
		printf("%d not found in queue\n",val_to_search);
	}
	
	//*******************************----------bst search kýsmý*******
		counter=0;
	if(bst_!=NULL && bst_->data==val_to_search){
		counter++;
		printf("%d result founded on 1.step\n",counter);
	}
	else {
	
	
		while(bst_->right!=NULL){//bst nin sað tarafýndan sona kadar arama yapýcaz
			bst_=bst_->right;
			if(bst_->right->data==val_to_search){
				counter++;
				bststep++;
				printf("%d result founded on %d. step\n",counter,bststep);
			}
			if(bst_->left->data==val_to_search){
				counter++;
				bststep++;
				printf("%d result founded on %d. step\n",counter,bststep);
			}
			bst_=bst_->right;
		}
		bst_=temp;
		while(bst_->left!=NULL){//bst nin sol tarafýndan sona kadar arama yapýcaz
		bst_=bst_->left;
			if(bst_->right->data==val_to_search){
				counter++;
				bststep++;
				printf("%d result founded on %d. step\n",counter,bststep);
			}
			if(bst_->left->data==val_to_search){
				counter++;
				bststep++;
				printf("%d result founded on %d. step\n",counter,bststep);
			}
			bst_=bst_->left;
			
		}
	}

}


void special_traverse(stack * stack_, queue * queue_, bst * bst_){//max-min,max-min,max-min þeklinde ortaya kadar sýralama
	




}





int main(){
	
	int data[SIZE]={5,2,7,8,11,3,21,7,6,15,19,35,24,1,8,12,17,8,23,4};
	bst *bst_=NULL;
	queue *queue_=NULL;
	stack *stack_=NULL;
	
	fill_structures(&stack_,&queue_,&bst_,data);
	
	ordered_print(stack_,queue_,bst_);

	//search(stack_,queue_,bst_,5);yapmaya çalýþtým ancak hata aldýðým için kapadým
	
	//special_traverse(stack_,queue_,bst_);
	
	return 0;
}

