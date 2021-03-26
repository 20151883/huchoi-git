cp ~/remote_ssh/vim_setting/id_dsa ~/.ssh/id_dsa
chmod 400 ~/.ssh/id_dsa
cat ~/remote_ssh/vim_setting/vimrc > ~/.vimrc
cat ~/remote_ssh/vim_setting/zshrc >> ~/.zshrc
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
	    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/plugin/Vundle.vim
