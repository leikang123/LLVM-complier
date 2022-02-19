/**
 * @author Leikang
 * @date 10/11/2021 -{TIME}
 */


/**
 * Token的一个简单实现。只有类型和文本值两个属性。
 */
public final class SimpleToken implements Token {
    //Token类型
    private TokenType type = null;

    //文本值
    private String text = null;


    @Override
    public TokenType getType() {

        return type;
    }

    @Override
    public String getText() {

        return text;
    }

    /**
     * 打印所有的Token
     *
     * @param tokenReader
     */
    public static void dump(SimpleLexer.SimpleTokenReader tokenReader) {
        System.out.println("text\ttype");
        Token token = null;
        while (( token = tokenReader.read() ) != null) {
            System.out.println(token.getText() + "\t\t" + token.getType());
        }
    }

}