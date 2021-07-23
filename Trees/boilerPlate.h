
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
class HDpair{
public:
	int height;
	int diameter;
};

void printTree(node* root)
{
	if(root==NULL)
	{
		return;
	}
	printTree(root->left);
	std::cout<<root->data<<" ";
	printTree(root->right);
}
void printLevelTree(node* root)
{
std::queue<node*>q;
q.push(root);
q.push(NULL);
	while(!q.empty())
	{
		node* data = q.front();
		q.pop();
		if(data==NULL && !q.empty())
		{
			std::cout<<"\n";
			q.push(NULL);
		}
		else if(data==NULL && q.empty()) std::cout<<"\n";
		else
		{
			std::cout<<data->data<<" ";
			if(data->left!=NULL)q.push(data->left);
			if(data->right!=NULL)q.push(data->right);
		}
	}

}
HDpair optimisedDiameter(node* root)
	{
		HDpair p;
		if(root==NULL)
		{
			p.height = p.diameter = 0;
			return p;
		}
		HDpair LST = optimisedDiameter(root->left);
		HDpair RST = optimisedDiameter(root->right);
		int D1 = LST.diameter;
		int D2 = RST.diameter;
		int D3 = LST.height + RST.height;
		p.height = std::max(LST.height,RST.height)+1;
		p.diameter = std::max(D1,std::max(D2,D3));
		return p;
	}

int height(node *root)
{
	if(root==NULL) return 0;
	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1+std::max(h1,h2);
}
int diameter(node *root)
{
	if(root==NULL) return 0;
	int d1 = diameter(root->left);
	int d2 = diameter(root->right);
	int d3 = height(root->left)+height(root->right);

	return std::max(std::max(d1,d2),d3);
}

node* buildTree(){
	int d;
	std::cin>>d;

	if(d==-1)
	{
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;

}
