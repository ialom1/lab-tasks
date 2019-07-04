import java.io.*;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task7 {
    public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException {

        String fileName = "src/temp.cpp";
        String line = null;
        String fileContent = "";
        Map<String,Integer> keywordMap,operatorMap,commentMap;
        keywordMap = new LinkedHashMap<>();
        operatorMap = new LinkedHashMap<>();
        commentMap = new LinkedHashMap<>();
        PrintWriter writer = new PrintWriter("src/keywords.txt", "UTF-8");
        try {

            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
//                System.out.println(line);
                fileContent+=line;
            }
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            ex.printStackTrace();
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            ex.printStackTrace();
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        String regexForKeyword = "(\\bint|\\bfloat|\\bdouble|\\bbreak|\\belse|\\bif|\\bbreak|\\blong|\\bswitch|\\bcase|\\benum|\\bregister|\\btypedef|\\bchar|\\bextern|\\breturn|\\bunion|\\bconst|\\bshort|\\bunsigned|\\bcontinue|\\bfor|\\bsigned|\\bvoid|\\bdefault|\\bgoto|\\bsizeof|\\bvolatile|\\bdo|\\bif|\\bstatic|\\bwhile)";
        String regexForOperator = "\\+{2}|\\-{2}|(==)|(<=)|(>=)|=|%|\\+|\\-|\\*|\\/|<|>";
        String regexForComment = "(?s)/\\*.*?\\*/";
        Pattern pattern = Pattern.compile(regexForKeyword);
        Matcher matcher = pattern.matcher(fileContent);
        System.out.println("Checking for Keywords.......Exported as txt");
        while (matcher.find()) {
            writer.print("Start index: " + matcher.start());
            writer.print(" End index: " + matcher.end() + " ");
            writer.println(matcher.group());
//            System.out.print("Start index: " + matcher.start());
//            System.out.print(" End index: " + matcher.end() + " ");
//            System.out.println(matcher.group());
            if(keywordMap.get(matcher.group())==null)
                keywordMap.put(matcher.group(),1);
            else {
                int val = keywordMap.get(matcher.group());
                val++;
                keywordMap.put(matcher.group(),val);
            }

        }

        writer.println("Summary for Keyword");
        for (Map.Entry<String,Integer> entry:keywordMap.entrySet())
        {
            writer.println("\'"+entry.getKey() +"\'"+ " is Presented " + entry.getValue()+" Times ");
        }

        writer.close();

        writer = new PrintWriter("src/operators.txt", "UTF-8");

        pattern = Pattern.compile(regexForOperator);
        matcher = pattern.matcher(fileContent);

        System.out.println("Checking for Operators.......Exported as txt");
        while (matcher.find()) {
            //System.out.print("Start index: " + matcher.start());
            //System.out.print(" End index: " + matcher.end() + " ");
            //System.out.println(matcher.group());
            writer.print("Start index: " + matcher.start());
            writer.print(" End index: " + matcher.end() + " ");
            writer.println(matcher.group());

            if(operatorMap.get(matcher.group())==null)
                operatorMap.put(matcher.group(),1);
            else {
                int val = operatorMap.get(matcher.group());
                val++;
                operatorMap.put(matcher.group(),val);
            }
        }

        writer.println("Summary for Operator");
        for (Map.Entry<String,Integer> entry:operatorMap.entrySet())
        {
            writer.println("\'"+entry.getKey()+"\'" + " is Presented " + entry.getValue()+" Times ");
        }


        writer.close();

        writer = new PrintWriter("src/comments.txt", "UTF-8");



        pattern = Pattern.compile(regexForComment);
        matcher = pattern.matcher(fileContent);

        System.out.println("Checking for Comment.......Exported as txt");
        while (matcher.find()) {
//            System.out.print("Start index: " + matcher.start());
//            System.out.print(" End index: " + matcher.end() + " ");
//            System.out.println(matcher.group());
            writer.print("Start index: " + matcher.start());
            writer.print(" End index: " + matcher.end() + " ");
            writer.println(matcher.group());
            if(commentMap.get(matcher.group())==null)
                commentMap.put(matcher.group(),1);
            else {
                int val = commentMap.get(matcher.group());
                val++;
                commentMap.put(matcher.group(),val);
            }
        }

        writer.println("Summary for Comments");
        for (Map.Entry<String,Integer> entry:commentMap.entrySet())
        {
            writer.println("\'"+entry.getKey()+"\'" + " is Presented " + entry.getValue()+" Times ");
        }
        writer.close();


    }
}
